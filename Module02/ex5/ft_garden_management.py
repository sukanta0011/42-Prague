class GardenError(Exception):
    """Exception raise for garden related errors"""
    pass


class PlantError(GardenError):
    """Exception raise for plants related errors"""
    pass


class WaterError(GardenError):
    """Exception raise for watering related errors"""
    pass


class GardenManager:
    """A class to manage plants health in the garden with robust
       error handling"""

    def __init__(self) -> None:
        self.plants = {}
        self.water_in_tank = 10

    def get_water_in_tank(self):
        """Get the current water level in the tank"""
        return self.water_in_tank

    def re_fill_water_tank(self):
        """Re-fill the tank"""
        self.water_in_tank = 10
        print("Water tank is full now")

    def add_plants(self, plants: list) -> None:
        """Add new plant to the garden"""
        for plant in plants:
            try:
                if len(plant) == 0:
                    raise ValueError("Error adding plant: Plant name cannot"
                                     " be empty!")
                elif plant is None:
                    raise ValueError("Error adding plant: Plant name cannot"
                                     " be None!")
                self.plants[str(plant.lower())] = {
                    "name": plant,
                    "water": 0,
                    "sunlight": 0
                }
                print(f"Added {plant.lower()} successfully")
            except ValueError as e:
                print(f"{e}")

    def log_sunlight_exposer(self, plant_name: str, sunlight: int):
        """Add the time duration of sun exposer of individual plants
           during the day"""
        try:
            self.plants[plant_name.lower()]["sunlight"] += int(sunlight)
        except KeyError:
            print(f"Caught KayError: {plant_name} not found. Check the" +
                  " plant list.")
        except ValueError:
            print(f"Caught ValueError: {sunlight} is not integer.")

    def add_extra_water(self, plant_name: str, water: int):
        """Add extra water to specific plants"""
        try:
            if self.water_in_tank > water:
                self.plants[plant_name]["water"] += int(water)
                self.water_in_tank -= int(water)
            else:
                raise WaterError("Caught GardenError: Not enough" +
                                 "water in tank")
        except KeyError:
            print(f"Caught KayError: {plant_name} not found. Check " +
                  "the plant list.")
        except ValueError:
            print(f"Caught ValueError: {water} is not integer.")
        except GardenError as e:
            print(f"{e}")

    def water_plants(self, water_amount: int = 1):
        """Water all the plants in the garden"""
        print("Opening watering system")
        water_amount = int(water_amount)
        try:
            for plant in self.plants:
                if self.water_in_tank > water_amount:
                    self.plants[plant]["water"] += water_amount
                    self.water_in_tank -= water_amount
                    print(f"Watering {self.plants[plant]["name"]} - success")
                else:
                    raise WaterError("Caught GardenError: Not enough" +
                                     "water in tank")
        except ValueError as e:
            print(f"{e}")
        except GardenError as e:
            print(f"{e}")
        finally:
            print("Closing watering system (cleanup)")

    def check_plant_health(self):
        """Show the current health status of all plants"""
        for plant in self.plants:
            try:
                name = self.plants[plant]["name"]
                water = self.plants[plant]["water"]
                sunlight = self.plants[plant]["sunlight"]

                if len(name) == 0:
                    raise ValueError("Error: Plant name cannot be empty!")

                if water < 1:
                    raise ValueError(f"Error checking {name}: Water " +
                                     f"level {water} is too low (min 1)")
                elif water > 10:
                    raise ValueError(f"Error checking {name}: Water " +
                                     f"level {water} is too high (max 10)")

                if sunlight < 2:
                    raise ValueError(f"Error checking {name}: Sunlight " +
                                     f"hours {sunlight} is too low (min 2)")
                elif sunlight > 12:
                    raise ValueError(f"Error checking {name}: Sunlight " +
                                     f"hours {sunlight} is too high (max 12)")

                print(f"Plant {name} is healthy " +
                      f"(water: {water}, " +
                      f"sunlight: {sunlight})")

            except ValueError as e:
                print(f"{e}")


def test_garden_manager():
    """Test the error handling of GardenManager"""
    my_garden = GardenManager()
    print("Adding plants to garden...")
    plants = ["tomato", "lettuce", ""]
    my_garden.add_plants(plants)
    print()

    print("Watering plants...")
    my_garden.water_plants()
    print()

    print("Checking plant health...")
    my_garden.log_sunlight_exposer("tomato", 5)
    my_garden.add_extra_water("lettuce", 10)
    my_garden.check_plant_health()
    print()

    print("Testing error recovery...")
    my_garden.add_extra_water("lettuce", 5)
    print("System recovered and continuing...")
    print()

    print("Garden management system test complete!")


if __name__ == "__main__":
    print("=== Garden Management System ===")
    test_garden_manager()
