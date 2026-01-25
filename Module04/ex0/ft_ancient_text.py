def main():
    """Read the data from a file"""
    file_name = "ancient_fragment.txt"

    try:
        print(f"Accessing Storage Vault: {file_name}")
        file = open(file_name, "r")
        print("Connection established...")
        print()
        print("RECOVERED DATA:")
        print(file.read())
        print()
        file.close()
        print("Data recovery complete. Storage unit disconnected.")
    except FileNotFoundError:
        print("ERROR: Storage vault not found. Run data generator first.")
    except PermissionError:
        print("Error: file reading access denied")
    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===")
    print()
    main()
