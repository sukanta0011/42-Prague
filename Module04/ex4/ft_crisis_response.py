import sys


def crisis_response(file_name):
    """Demonstrate the use of error handling"""
    print(f"CRISIS ALERT: Attempting access to '{file_name}'...",
          file=sys.stderr)
    try:
        with open(file_name, "r") as file:
            print(f"SUCCESS: Archive recovered - \"{file.read()}\"")
        print("STATUS: Normal operations resumed")
    except FileNotFoundError:
        print("RESPONSE: Archive not found in storage matrix")
        print("STATUS: Crisis handled, system stable")
    except PermissionError:
        print("RESPONSE: Security protocols deny access")
        print("STATUS: Crisis handled, security maintained")
    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    print("=== CYBER ARCHIVES - CRISIS RESPONSE SYSTEM ===")
    print()
    crisis_response("lost_archive.txt")
    print()
    crisis_response("classified_vault.txt")
    print()
    crisis_response("standard_archive.txt")
    print()
    print("All crisis scenarios handled successfully. Archives secure.")
