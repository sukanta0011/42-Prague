def check_temperature(temp_str: str) -> int | None:
    """Convert the provide temperature string to int and return if
       it is with in valid range of 0-40°C"""
    try:
        temp = int(temp_str)
        if (temp > 40):
            print(f"Error: {temp}°C is too hot for plants (max 40°C)")
        elif (temp < 0):
            print(f"Error: {temp}°C is too cold for plants (min 0°C)")
        else:
            print(f"Temperature {temp}°C is perfect for plants!")
            return temp

    except Exception:
        print(f"Error: {temp_str} is not a valid number")
    return None


def test_temperature_input():
    """Tester function to test check_temperature function"""
    test_cases = ["25", "abc", "100", "-50", "30.5"]
    for val in test_cases:
        print(f"Testing temperature: {val}")
        check_temperature(val)
        print()
    print("All tests completed")
    print("program didn't crash!")


if __name__ == "__main__":
    print("=== Garden Temperature Checker ===")
    test_temperature_input()
