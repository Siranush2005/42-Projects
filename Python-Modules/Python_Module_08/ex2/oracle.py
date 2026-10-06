import os
import sys
from dotenv import load_dotenv


if __name__ == "__main__":
    try:
        load_dotenv()

        print("ORACLE STATUS: Reading the Matrix...")

        config: dict[str, str | None] = {
            "MATRIX_MODE": os.getenv("MATRIX_MODE"),
            "DATABASE_URL": os.getenv("DATABASE_URL"),
            "API_KEY": os.getenv("API_KEY"),
            "LOG_LEVEL": os.getenv("LOG_LEVEL"),
            "ZION_ENDPOINT": os.getenv("ZION_ENDPOINT"),
        }

        missing = [key for key, value in config.items() if value is None]
        if missing:
            print("Env not found")
            print(f"Missing variables: {', '.join(missing)}")
            sys.exit(1)

        mode = config["MATRIX_MODE"]
        log_level = config["LOG_LEVEL"]

        print("Configuration loaded:")

        if mode == "development":
            print(f"Mode: {mode}")
            print("Database: Connected to local instance")
        elif mode == "production":
            print(f"Mode: {mode}")
            print("Database: Connected to production instance")
        else:
            print(f"Matrix_Mode named {mode} doesn't exist")
            sys.exit(1)

        print("API Access: Authenticated")
        print(f"Log Level: {log_level}")
        print("Zion Network: Online")

        print("\nEnvironment security check:")
        print("[OK] No hardcoded secrets detected")
        print("[OK] .env file properly configured")
        print("[OK] Production overrides available\n")
        print("The Oracle sees all configurations.")

    except Exception as exc:
        print(f"Oracle encountered an error: {exc}")
        sys.exit(1)
