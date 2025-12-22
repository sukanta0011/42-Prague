def check_plant_health(plant_name: str, water_level: int,
                       sunlight_hours: int):
    """Validate plant health"""

    if len(plant_name) == 0:
        raise ValueError("Error: Plant name cannot be empty!")

    if water_level < 1:
        raise ValueError(f"Error: Water level {water_level} is " +
                         "too low (min 1)")
    elif water_level > 10:
        raise ValueError(f"Error: Water level {water_level} is " +
                         "too high (max 10)")

    if sunlight_hours < 2:
        raise ValueError(f"Error: Sunlight hours {sunlight_hours} is " +
                         "too low (min 2)")
    elif sunlight_hours > 12:
        raise ValueError(f"Error: Sunlight hours {sunlight_hours} is " +
                         "too high (max 12)")

    print(f"Plant '{plant_name}' is healthy!")
    print(f"Water level {water_level} is fine.")
    print(f"Sunlight hours {sunlight_hours} is sufficient.")


def test_plant_checks():
    """testing the error handling of check_plant_health() function"""
    print("Testing good values...")
    check_plant_health("tomato", 5, 6)
    print()
    print("Testing empty plant name..")
    try:
        check_plant_health("", 5, 6)
    except ValueError as e:
        print(f"{e}")
    print()
    print("Testing bad water level...")
    try:
        check_plant_health("tomato", 15, 6)
    except ValueError as e:
        print(f"{e}")
    print()
    print("Testing bad sunlight hours...")
    try:
        check_plant_health("tomato", 5, 1)
    except ValueError as e:
        print(f"{e}")
    print()
    print("All error raising tests completed!")


if __name__ == "__main__":
    print("=== Garden Plant Health Checker ===")
    test_plant_checks()
