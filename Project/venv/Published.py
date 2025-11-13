import os
import time
import pyodbc
from datetime import datetime
from telegram import Bot
from dotenv import load_dotenv
import asyncio
import html
from pathlib import Path

SCRIPT_DIR = Path(__file__).resolve()
PROJECT_DIR = SCRIPT_DIR.parent.parent
MEDIA_ROOT = PROJECT_DIR / "x64" / "Debug" / "FilePost"

print(f"📁 Скрипт: {SCRIPT_DIR}")
print(f"📂 Проект: {PROJECT_DIR}")
print(f"📤 Папка медиафайлов: {MEDIA_ROOT}")

env_path = SCRIPT_DIR.parent / "Data.env"
load_dotenv(env_path)
print(f"✅ Загружен Data.env из: {env_path}")

TELEGRAM_BOT_TOKEN = os.getenv("TELEGRAM_BOT_TOKEN")
if not TELEGRAM_BOT_TOKEN:
    raise ValueError("Не задан TELEGRAM_BOT_TOKEN в Data.env")

def get_db_connection():
    server = os.getenv("SQL_SERVER")
    database = os.getenv("SQL_DATABASE")
    trusted = os.getenv("SQL_TRUSTED_CONNECTION", "yes").lower() == "yes"
    
    if trusted:
        conn_str = (
            f"DRIVER={{ODBC Driver 17 for SQL Server}};"
            f"SERVER={server};"
            f"DATABASE={database};"
            f"Trusted_Connection=yes;"
        )
    else:
        username = os.getenv("SQL_USERNAME")
        password = os.getenv("SQL_PASSWORD")
        conn_str = (
            f"DRIVER={{ODBC Driver 17 for SQL Server}};"
            f"SERVER={server};"
            f"DATABASE={database};"
            f"UID={username};"
            f"PWD={password};"
        )
    return pyodbc.connect(conn_str)

def format_post(row):
    name = row[1] if row[1] else ""
    text = row[3] if row[3] else ""
    return f"<b>{html.escape(str(name))}</b>\n\n{html.escape(str(text))}"

async def publish_unpublished_posts():
    bot = Bot(token=TELEGRAM_BOT_TOKEN)
    current_time = datetime.now()
    print(f"[{current_time.strftime('%Y-%m-%d %H:%M:%S')}] Проверка постов...")

    try:
        with get_db_connection() as conn:
            cursor = conn.cursor()
            cursor.execute("""
                SELECT DISTINCT tp.Users_ID, l.ID_Group
                FROM TablePost tp
                INNER JOIN Login l ON tp.Users_ID = l.ID
                WHERE tp.Published = 0
                  AND tp.Date_post <= ?
                  AND l.ID_Group IS NOT NULL
            """, (current_time,))
            user_channel_map = {user_id: channel_id for user_id, channel_id in cursor.fetchall()}

        if not user_channel_map:
            print("Нет постов для публикации.")
            return

        for user_id, channel_id in user_channel_map.items():
            if not channel_id or not str(channel_id).strip():
                print(f"⚠️ Пропущен пользователь {user_id}: не указан ID_Group")
                continue

            try:
                with get_db_connection() as conn:
                    cursor = conn.cursor()
                    cursor.execute("""
                        SELECT [ID], [name_post], [About_post], [Text_post], [Scencens_post], [ViewMedia_post], [Files]
                        FROM TablePost
                        WHERE Users_ID = ? AND Published = 0 AND Date_post <= ?
                        ORDER BY Date_post
                    """, (user_id, current_time))
                    posts = cursor.fetchall()

                for post in posts:
                    post_id = post[0]
                    try:
                        message_text = format_post(post)
                        file_rel_path = post[6]

                        file_to_send = None
                        if file_rel_path:
                            filename = os.path.basename(str(file_rel_path))
                            full_path = MEDIA_ROOT / filename
                            if full_path.exists():
                                file_to_send = full_path.resolve()
                                print(f"✅ Файл найден: {full_path}")
                            else:
                                print(f"❌ Файл не найден: {full_path}")

                        if file_to_send:
                            with open(file_to_send, 'rb') as f:
                                ext = file_to_send.suffix.lower()
                                if ext in ('.jpg', '.jpeg', '.png', '.gif', '.webp'):
                                    await bot.send_photo(chat_id=channel_id, photo=f, caption=message_text, parse_mode='HTML')
                                elif ext in ('.mp4', '.avi', '.mov', '.mkv', '.wmv'):
                                    await bot.send_video(chat_id=channel_id, video=f, caption=message_text, parse_mode='HTML')
                                elif ext in ('.mp3', '.ogg', '.wav', '.flac'):
                                    await bot.send_audio(chat_id=channel_id, audio=f, caption=message_text, parse_mode='HTML')
                                else:
                                    await bot.send_document(chat_id=channel_id, document=f, caption=message_text, parse_mode='HTML')
                        else:
                            await bot.send_message(chat_id=channel_id, text=message_text, parse_mode='HTML')

                        print(f"✅ Опубликован пост ID={post_id} в канал {channel_id}")

                        with get_db_connection() as conn_update:
                            cursor_u = conn_update.cursor()
                            cursor_u.execute("UPDATE TablePost SET Published = 1 WHERE ID = ?", (post_id,))
                            conn_update.commit()

                        await asyncio.sleep(1)

                    except Exception as e:
                        print(f"❌ Ошибка публикации поста ID={post_id}: {e}")

            except Exception as e:
                print(f"❌ Ошибка при обработке пользователя {user_id}: {e}")

    except Exception as e:
        print(f"💥 Критическая ошибка: {e}")

async def main():
    while True:
        await publish_unpublished_posts()
        await asyncio.sleep(10)

if __name__ == '__main__':
    asyncio.run(main())