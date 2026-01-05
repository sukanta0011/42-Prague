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
    """Get the current condition of the plant"""
    bad_conditions = ["wilting", "dead"]
    condition = "wilting"
    if condition in bad_conditions:
        raise PlantError(f"{plant_name} is {condition}!")


def get_water_levels():
    """Get the current water level in the tank"""
    water_level = 0
    if water_level <= 2:
        raise WaterError("Not enough water in the tank!")
    elif water_level > 10:
        raise WaterError("Tank is full, stop the pump.")
    else:
        return water_level


def test_custom_error():
    """Testing custom errors related to garden"""
    plant_name = "Tomato"
    print()
    print("Testing PlantError...")
    try:
        get_plant_condition(plant_name)
    except PlantError as e:
        print(f"Caught PlantError: {e}")

    print()
    print("Testing WaterError...")
    try:
        get_water_levels()
    except WaterError as e:
        print(f"Caught WaterError: {e}")

    print()
    print("Testing GardenError...")
    try:
        get_plant_condition(plant_name)
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    try:
        get_water_levels()
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    print("All error types tested successfully!")


if __name__ == "__main__":
    print("=== Garden Error Types Demo ===")
    test_custom_error()
