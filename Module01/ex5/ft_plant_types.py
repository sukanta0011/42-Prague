class Plant:
    """A class representing a plant the community garden registry"""

    def __init__(self, name: str, height: int, age: int) -> None:
        """Initializing the new plant with name, age and height."""
        self.name = name
        self.height = height
        self.plant_age = age

    def get_info(self) -> None:
        """Get the current state of the plant."""
        print(f"{self.name}: {self.height}cm, {self.plant_age} days old")

    def grow(self, growth_rate: int = 1) -> None:
        """Increase the plant height by growth rate."""
        self.height += growth_rate

    def age(self) -> None:
        """Increase the plant age by a day."""
        self.plant_age += 1


class Flower(Plant):
    """A class representing a Flower type plant in the community garden"""

    def __init__(self, name: str, height: int, age: int, color: str) -> None:
        """Initializing a new Flower plant with name, age, height
           and flower colour"""
        super().__init__(name, height, age)
        self.color = color
        print(f"{self.name} (Flower): {self.height}cm, " +
              f"{self.plant_age} days, {self.color}")

    def bloom(self) -> None:
        """Bloom the flower"""
        print(f"{self.name} is blooming beautifully!")


class Tree(Plant):
    """A class representing a Tree in the community garden"""

    def __init__(self, name: str, height: int, age: int,
                 trunk_diameter: int) -> None:
        """Initializing a new Tree with name, age(days), height(cm)
           and trunk diameter(cm)"""
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter
        print(f"{self.name} (Tree): {self.height}cm, " +
              f"{self.plant_age} days, {self.trunk_diameter}cm diameter")

    def produce_shade(self, shade_area: int):
        """Produce shade by provided area in m^2"""
        print(f"{self.name} provides {shade_area}" +
              "square meters of shade")


class Vegetable(Plant):
    """
    A class representing a Vegetable in the community garden
    """

    def __init__(self, name: str, height: int, age: int,
                 harvest_season: str, nutritional_value: str) -> None:
        """Initializing a new vegetable with name, age(days), height(cm)
           , harvest season and nutrition_value (ex. vitamin A/B/C/D ...)"""
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value
        print(f"{self.name} (Vegetable): {self.height}cm, " +
              f"{self.plant_age} days, {self.harvest_season} harvest")
        print(f"{self.name} is rich in {self.nutritional_value}")


if __name__ == "__main__":
    print("=== Plant Factory Output ===\n")
    rose = Flower("Rose", 25, 30, "red color")
    rose.bloom()
    sunflower = Flower("Sunflower", 50, 15, "yellow")
    sunflower.bloom()
    print()
    oak = Tree("Oak", 500, 1825, 50)
    oak.produce_shade(78)
    pine = Tree("Pine", 300, 1000, 30)
    pine.produce_shade(45)
    print()
    tomato = Vegetable("Tomato", 80, 90, "summer", "vitamin C")
    carrot = Vegetable("Carrot", 20, 60, "autumn", "vitamin A")
