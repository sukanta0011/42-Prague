def vault_security():
    extract_file = "classified_data.txt"
    preserve_file = "security_protocols.txt"

    preservation_txt = "[CLASSIFIED] New security protocols archived"
    print("Initiating secure vault access..")
    try:
        print("Vault connection established with failsafe protocols")
        print()
        print("SECURE EXTRACTION:")
        with open(extract_file, "r") as data:
            print(data.read())
        print()
        print("SECURE PRESERVATION:")
        with open(preserve_file, "w") as data:
            print(preservation_txt)
            data.write(preservation_txt)
        print("Vault automatically sealed upon completion")
        print()
        print("All vault operations completed with maximum security.")
    except FileNotFoundError:
        print("ERROR: Storage vault not found.")


if __name__ == "__main__":
    print("=== CYBER ARCHIVES - VAULT SECURITY SYSTEM ===")
    vault_security()
