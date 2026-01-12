def create_archive(data: list) -> None:
    """Write the data to a file"""
    file_name = "new_discovery.txt"
    try:
        print(f"Initializing new storage unit: {file_name}")
        file = open(file_name, "w")
        print("Storage unit created successfully...")
        print()
        print("Inscribing preservation data...")
        for i, info in enumerate(data):
            i += 1
            print(f"{{[}}ENTRY {i:03d}{{]}} {info}")
            file.write(f"{{[}}ENTRY {i:03d}{{]}} {info}\n")
        print()
        file.close()
        print("Data inscription complete. Storage unit sealed.")
        print(f"Archive '{file_name}' ready for long-term preservation.")
    except PermissionError:
        print("Error: file writing access denied")


if __name__ == "__main__":
    print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===")
    info1 = "New quantum algorithm discovered"
    info2 = "Efficiency increased by 347%"
    info3 = "Archived by Data Archivist trainee"
    info_list = [info1, info2, info3]
    print()
    create_archive(info_list)
