import sys
import os
import site

global_str = """WARNING: You're in the global environment!
The machines can see everything you install.
To enter the construct, run:
python -m venv matrix_env
source matrix_env/bin/activate # On Unix
matrix_env
Scripts
activate # On Windows\n
Then run this program again."""

venv_str = """SUCCESS: You're in an isolated environment!
Safe to install packages without affecting
the global system.
"""


def is_in_venv() -> bool:
    """Check if we are in virtual environment or not"""
    main_python = sys.base_prefix
    current_python = sys.prefix
    if main_python == current_python:
        return False
    else:
        return True


if __name__ == "__main__":
    try:
        if (is_in_venv()):
            print("MATRIX STATUS: Welcome to the construct\n")
            print(f"Current Python: {sys.executable}")
            env_path = sys.prefix
            env_name = os.path.basename(env_path)
            print(f"Virtual Environment: {env_name}")
            print(f"Environment Path: {env_path}")
            print()
            print(venv_str)
            print("Package installation path:")
            paths = site.getsitepackages()
            for path in paths:
                if "site-packages" in path:
                    print(path)
        else:
            print("MATRIX STATUS: You're still plugged in\n")
            print(f"Current Python: {sys.executable}")
            print("Virtual Environment: None detected\n")
            print(global_str)
    except Exception as e:
        print(f"Error: {e}")
