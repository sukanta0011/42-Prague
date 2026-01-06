import sys

total_args = len(sys.argv)
print("=== Command Quest ===")
if total_args == 1:
    print("No arguments provided")

print(f"Program name: {sys.argv[0]}")

if total_args > 1:
    print(f"Arguments received: {total_args - 1}")

try:
    for idx, arg in enumerate(sys.argv[1:]):
        print(f"Argument {idx + 1}: {arg}")
except Exception:
    pass

print(f"Total arguments: {total_args}")
