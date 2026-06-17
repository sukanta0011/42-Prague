import os
from dotenv import load_dotenv


def connect_to_db(url: str) -> bool:
    """Demo function, just print required output"""
    print("Database: Connected to local instance")
    return True


def establish_api_connection(api_key: str) -> bool:
    """Demo function, just print required output"""
    print("API Access: Authenticated")
    return True


def check_upload_link(url: str) -> bool:
    """Demo function, just print required output"""
    print("Zion Network: Online")
    return True


def load_configuration():
    """Load configuration details from the .env file"""
    if os.path.exists(".env") and load_dotenv():
        mode = os.getenv('MATRIX_MODE')
        db_url = os.getenv('DATABASE_URL')
        api_key = os.getenv('API_KEY')
        log_level = os.getenv('LOG_LEVEL', 'INFO')
        upload_url = os.getenv('ZION_ENDPOINT')
        if mode is not None:
            print(f"Mode: {mode}")
        else:
            print("Mode: Not defined")
        if db_url is not None:
            connect_to_db(db_url)
        else:
            print("Database: Not available")
        if api_key is not None:
            establish_api_connection(api_key)
        else:
            print("API Key: Not available")
        print(f"Log Level: {log_level}")
        if upload_url is not None:
            check_upload_link(upload_url)
        else:
            print("Zion Network: Not available")
    else:
        print("Error: '.env' file not found/ loading failed")


def environment_security_check(api_key_before: str | None):
    """Check that environment variables are loaded from .env file"""
    print("Environment security check:")
    env_exists = os.path.exists(".env")
    api_key_now = os.getenv('API_KEY')
    if api_key_now is not None and\
       api_key_now != api_key_before:
        print("[OK] No hardcoded secrets detected")
    else:
        print("[KO] hardcoded secrets detected")

    if (env_exists):
        print("[OK] .env file properly configured")
    else:
        print("[KO] .env file not-properly configured")

    if os.getenv('MATRIX_MODE') == "production":
        print("[OK] Production overrides available")
    else:
        print("[KO] Production overrides not used")


if __name__ == "__main__":
    print("ORACLE STATUS: Reading the Matrix...")
    print()
    api_key_before = os.getenv('API_KEY')
    load_configuration()
    print()
    environment_security_check(api_key_before)
    print()
    print("The Oracle sees all configurations.")
