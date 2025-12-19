class GardenError(Exception):
    """Exception raise for garden related errors"""
    pass


class PlantError(GardenError):
    """Exception raise for plants related errors"""
    pass


class WaterError(GardenError):
    """Exception raise for watering related errors"""
    pass

def get_plant_condition(plant_name: str):
    bad_conditions = ["wilting", "dead"]
    condition = "wilting"
    if condition in bad_conditions:
        raise PlantError


def test_custom():
    """Testing the error handling of garden operation"""
    plants_info = {"Rose": 10}
    fake_path = "missing.txt"

    print("Testing ValueError...")
    garden_operations(height="abc")
    print()

    print("Testing ZeroDivisionError...")
    garden_operations(height="10", days=0)
    print()

    print("Testing FileNotFoundError...")
    garden_operations(log_path=fake_path)
    print()

    print("Testing KeyError...")
    garden_operations(plants_info=plants_info)
    print()

    print("Testing multiple errors together...")
    val = 0
    try:
        val = int("abc")
    except (ValueError, FileNotFoundError, ZeroDivisionError, KeyError):
        pass
    print("Caught an error, but program continues")
    print()
    return val


if __name__ == "__main__":
    print("=== Garden Error Types Demo ===")
    test_error_types()
    print("All error types tested successfully!")