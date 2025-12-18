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
        print(f"{self.name} grew {growth_rate}cm")

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

    def grow(self, growth_rate: int = 1) -> None:
        self.height += growth_rate
        print(f"{self.name} Tree grew {growth_rate}cm")

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


class PrizeFlower(Flower):
    def __init__(self, name: str, height: int, age: int, color: str,
                 prize_points: int) -> None:
        super().__init__(name, height, age, color)
        self.prize_points = prize_points


class GardenManager:
    def __init__(self, owner: str) -> None:
        self.owner = owner
        self.garden_stats = self.GardenStats()
        self.plants = {}

    def add_plant(self, plant: object) -> None:
        self.plants[plant.name] = plant
        if plant.__class__ == Tree:
            print(f"Added {plant.name} Tree to {self.owner}'s garden")
        else:
            print(f"Added {plant.name} to {self.owner}'s garden")

    def garden_report(self) -> None:
        print("Plants in garden")
        for _, plant in self.plants.items():
            if plant.__class__ == Tree:
                print(f" - {plant.name} Tree: {plant.height}cm")
            elif plant.__class__ == Flower:
                print(f" - {plant.name}: {plant.height}cm," +
                      f"{plant.color} flowers (blooming)")
            elif plant.__class__ == PrizeFlower:
                print(f" - {plant.name}: {plant.height}cm," +
                      f"{plant.color} flowers (blooming), " +
                      f"Prize points: {plant.prize_points}")
            else:
                print(f" - {plant.name}: {plant.height}cm")
    
    @classmethod
    def create_garden_network(cls):
        pass

    class GardenStats:
        pass


if __name__ == "__main__":
    print("=== Garden Management System Demo ===")
    print()
    alice = GardenManager("Alice")
    rose = Flower("Rose", 25, 30, "red color")
    sunflower = PrizeFlower("Sunflower", 50, 15, "yellow", 10)
    oak = Tree("Oak", 500, 1825, 50)
    alice.add_plant(oak)
    alice.add_plant(rose)
    alice.add_plant(sunflower)
    print()
    print("Alice is helping all plants grow...")
    alice.plants["Oak"].grow()
    alice.plants["Rose"].grow()
    alice.plants["Sunflower"].grow()
    print()
    print("=== Alice's Garden Report ===")
    alice.garden_report()


