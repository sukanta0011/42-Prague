def water_plants(plant_list):
    """Water all the provided plants"""
    print("Opening watering system")
    try:
        for plant in plant_list:
            if plant is not None:
                print(f"Watering {plant}")
            else:
                raise ValueError("Error: Cannot water None - invalid plant!")
        print("Watering completed successfully!")
    except ValueError as e:
        print(f"{e}")
    finally:
        print("Closing watering system (cleanup)")


def test_watering_system():
    """Test function for watering system"""
    print("Testing normal watering...")
    plants = ["tomato", "lettuce", "carrots"]
    water_plants(plants)

    print()
    print("Testing with error...")
    plants = ["tomato", None]
    water_plants(plants)


if __name__ == "__main__":
    print("=== Garden Watering System ===")
    print()
    test_watering_system()

    print("Cleanup always happens, even with errors!")