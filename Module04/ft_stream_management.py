import sys


def stream_manager():
    """Show the use of stdin, stdout and stderror"""
    id = input("Input Stream active. Enter archivist ID: ")
    msg = input("Input Stream active. Enter status report: ")
    print()
    print(f"{{[}}STANDARD{{]}} Archive status from {id}: {msg}",
          file=sys.stdout)
    print("{[}ALERT{]} System diagnostic: Communication channels verified",
          file=sys.stderr)
    print("{[}STANDARD{]} Data transmission complete",
          file=sys.stdout)
    print()
    print("Three-channel communication test successful.")


if __name__ == "__main__":
    print("=== CYBER ARCHIVES - COMMUNICATION SYSTEM ===")
    stream_manager()
