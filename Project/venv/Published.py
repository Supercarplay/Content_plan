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
CONTENT_PLAN_DIR = PROJECT_DIR.parent
MEDIA_ROOT = PROJECT_DIR / "x64" / "Debug"

print(f"📁 Скрипт: {SCRIPT_DIR}")
print(f"📂 Проект: {PROJECT_DIR}")
print(f"📦 Content_plan: {CONTENT_PLAN_DIR}")
print(f"📤 Корень медиафайлов и БД: {MEDIA_ROOT}")

env_path = SCRIPT_DIR.parent / "Data.env"
if not env_path.exists():
    raise FileNotFoundError(f"Файл Data.env не найден: {env_path}")

load_dotenv(env_path)
print(f"✅ Загружен Data.env из: {env_path}")

TELEGRAM_BOT_TOKEN = os.getenv("TELEGRAM_BOT_TOKEN")
if not TELEGRAM_BOT_TOKEN:
    raise ValueError("Не задан TELEGRAM_BOT_TOKEN в Data.env")

POST_DB_NAME = "Database_post.accdb"
LOGIN_DB_NAME = "Database_Login.accdb"

post_db_path = MEDIA_ROOT / POST_DB_NAME
login_db_path = MEDIA_ROOT / LOGIN_DB_NAME

if not post_db_path.exists():
    raise FileNotFoundError(f"База данных постов не найдена: {post_db_path}")
if not login_db_path.exists():
    raise FileNotFoundError(f"База данных логинов не найдена: {login_db_path}")

print(f"📁 База постов: {post_db_path}")
print(f"📂 База логинов: {login_db_path}")

def get_channel_id_from_login_db():
    conn_str = (
        r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};'
        f'DBQ={login_db_path};'
    )
    try:
        with pyodbc.connect(conn_str) as conn:
            cursor = conn.cursor()
            cursor.execute("SELECT TOP 1 ID_Group FROM Login")
            row = cursor.fetchone()
            if row and row[0]:
                return str(row[0]).strip()
            else:
                raise ValueError("Не удалось получить ID канала из таблицы Login")
    except Exception as e:
        raise RuntimeError(f"Ошибка при чтении ID канала: {e}")

try:
    TELEGRAM_CHANNEL_ID = get_channel_id_from_login_db()
    print(f"✅ ID канала получен из базы: {TELEGRAM_CHANNEL_ID}")
except Exception as e:
    raise RuntimeError(f"❌ Не удалось получить ID канала: {e}")

def get_post_db_connection():
    conn_str = (
        r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};'
        f'DBQ={post_db_path};'
    )
    return pyodbc.connect(conn_str)

def format_post(row):
    id_post, name, about, text, continuity, media, files = row
    msg = f"<b>{html.escape(name)}</b>\n\n{html.escape(text)}"
    return msg

async def publish_unpublished_posts():
    try:
        conn = get_post_db_connection()
        cursor = conn.cursor()
        current_time = datetime.now()

        cursor.execute("""
            SELECT [ID], [name_post], [About_post], [Text_post], [Scencens_post], [ViewMedia_post], [Files]
            FROM TablePost
            WHERE ([Published] = False OR [Published] IS NULL)
              AND [Date_post] <= ?
            ORDER BY [Date_post]
        """, (current_time,))

        posts = cursor.fetchall()
        conn.close()

        if not posts:
            print("Нет постов для публикации.")
            return

        bot = Bot(token=TELEGRAM_BOT_TOKEN)

        for post in posts:
            try:
                id_post, name, about, text, continuity, media, file_rel_path = post
                message_text = format_post(post)

                file_to_send = None

                if file_rel_path:
                    file_rel_path = str(file_rel_path).strip()
                    if file_rel_path:
                        full_path = MEDIA_ROOT / file_rel_path
                        if full_path.exists() and full_path.is_file():
                            file_to_send = full_path.resolve()
                            print(f"✅ Файл найден: {full_path}")
                        else:
                            print(f"❌ Файл не найден: {full_path}")
                    else:
                        print("⚠️ Поле 'Files' пустое или содержит только пробелы")

                if file_to_send:
                    with open(file_to_send, 'rb') as f:
                        ext = file_to_send.suffix.lower()
                        if ext in ('.jpg', '.jpeg', '.png', '.gif', '.webp'):
                            await bot.send_photo(
                                chat_id=TELEGRAM_CHANNEL_ID,
                                photo=f,
                                caption=message_text,
                                parse_mode='HTML'
                            )
                        elif ext in ('.mp4', '.avi', '.mov', '.mkv', '.wmv'):
                            await bot.send_video(
                                chat_id=TELEGRAM_CHANNEL_ID,
                                video=f,
                                caption=message_text,
                                parse_mode='HTML'
                            )
                        elif ext in ('.mp3', '.ogg', '.wav', '.flac'):
                            await bot.send_audio(
                                chat_id=TELEGRAM_CHANNEL_ID,
                                audio=f,
                                caption=message_text,
                                parse_mode='HTML'
                            )
                        else:
                            await bot.send_document(
                                chat_id=TELEGRAM_CHANNEL_ID,
                                document=f,
                                caption=message_text,
                                parse_mode='HTML'
                            )
                else:
                    await bot.send_message(
                        chat_id=TELEGRAM_CHANNEL_ID,
                        text=message_text,
                        parse_mode='HTML'
                    )

                print(f"✅ Опубликован пост: {name}")

                conn2 = get_post_db_connection()
                cursor2 = conn2.cursor()
                cursor2.execute("UPDATE TablePost SET [Published] = ? WHERE [ID] = ?", (True, id_post))
                conn2.commit()
                conn2.close()

                await asyncio.sleep(1)

            except Exception as e:
                print(f"❌ Ошибка публикации поста ID={post[0]}: {e}")

    except Exception as e:
        print(f"💥 Критическая ошибка: {e}")

async def main():
    while True:
        print(f"\n[{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}] Проверка новых постов...")
        await publish_unpublished_posts()
        await asyncio.sleep(10)  # 10 минут

if __name__ == '__main__':
    asyncio.run(main())