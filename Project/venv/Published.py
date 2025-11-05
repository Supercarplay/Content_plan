import os
import time
import pyodbc
from datetime import datetime
from telegram import Bot
from dotenv import load_dotenv
import asyncio
import html
from pathlib import Path

env_path = Path(__file__).parent / "Data.env"
if not env_path.exists():
    raise FileNotFoundError(f"Файл Data.env не найден по пути: {env_path}")

load_dotenv(env_path)
print(f"✅ Загружен Data.env из: {env_path}")

TELEGRAM_BOT_TOKEN = os.getenv("TELEGRAM_BOT_TOKEN")
TELEGRAM_CHANNEL_ID = os.getenv("TELEGRAM_CHANNEL_ID")
DB_PATH = os.getenv("DB_PATH")

print("🔍 Загруженные значения:")
print(f"  TELEGRAM_BOT_TOKEN = {'[скрыто]' if TELEGRAM_BOT_TOKEN else 'None'}")
print(f"  TELEGRAM_CHANNEL_ID = {TELEGRAM_CHANNEL_ID}")
print(f"  DB_PATH = {DB_PATH}")

if not TELEGRAM_BOT_TOKEN:
    raise ValueError("Не задан TELEGRAM_BOT_TOKEN в Data.env файле")
if not TELEGRAM_CHANNEL_ID:
    raise ValueError("Не задан TELEGRAM_CHANNEL_ID в Data.env файле")
if not DB_PATH:
    raise ValueError("Не задан DB_PATH в Data.env файле")


if not os.path.exists(DB_PATH):
    raise FileNotFoundError(f"База данных не найдена по пути: {DB_PATH}")


def get_db_connection():
    conn_str = (
        r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};'
        f'DBQ={DB_PATH};'
    )
    return pyodbc.connect(conn_str)


def format_post(row):
    id_post, name, about, text, continuity, media = row

    name = html.escape(name) if name else ""
    about = html.escape(about) if about else ""
    text = html.escape(text) if text else ""
    continuity = html.escape(continuity) if continuity else ""
    media = html.escape(media) if media else ""

    msg = f"{text}\n\n"

    return msg


async def publish_unpublished_posts():
    try:
        conn = get_db_connection()
        cursor = conn.cursor()

        current_time = datetime.now()

        cursor.execute("""
            SELECT [ID], [name_post], [About_post], [Text_post], [Scencens_post], [ViewMedia_post]
            FROM TablePost
            WHERE ([Published] = False OR [Published] IS NULL)
              AND [Date_post] <= ?
            ORDER BY [Date_post]
        """, (current_time,))

        posts = cursor.fetchall()
        conn.close()

        if not posts:
            print("Нет постов для публикации (либо ещё не наступило время).")
            return

        bot = Bot(token=TELEGRAM_BOT_TOKEN)

        for post in posts:
            try:
                message = format_post(post)
                await bot.send_message(
                    chat_id=TELEGRAM_CHANNEL_ID,
                    text=message,
                    parse_mode='HTML'
                )
                print(f"Опубликован пост: {post[1]}")

                conn2 = get_db_connection()
                cursor2 = conn2.cursor()
                cursor2.execute("UPDATE TablePost SET [Published] = ? WHERE [ID] = ?", (True, post[0]))
                conn2.commit()
                conn2.close()

                await asyncio.sleep(1)

            except Exception as e:
                print(f"Ошибка публикации поста ID={post[0]}: {e}")

    except Exception as e:
        print(f"Критическая ошибка: {e}")


async def main():
    while True:
        print(f"\n[{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}] Проверка новых постов...")
        await publish_unpublished_posts()
        await asyncio.sleep(600)  # 10 минут


if __name__ == '__main__':
    asyncio.run(main())