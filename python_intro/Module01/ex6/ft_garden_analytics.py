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


class FloweringPlant(Plant):
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


class PrizeFlower(FloweringPlant):
    """class representing prize flowers in community garden"""
    def __init__(self, name: str, height: int, age: int, color: str,
                 prize_points: int) -> None:
        super().__init__(name, height, age, color)
        self.prize_points = prize_points


class GardenManager:
    """Class representing the centralized system garden manager which tracks
       all the plant information of multiple gardens together"""
    total_gardens = 0

    def __init__(self, owner: str) -> None:
        """Initialize the garden manager by the garden's owner name"""
        self.owner = owner
        self.garden_stats = self.GardenStats()
        self.plants = {}
        GardenManager.total_gardens += 1

    def register_plant(self, plant: Plant) -> None:
        """Register new plants to the garden manager"""
        self.plants[plant.name] = plant
        self.garden_stats.add(plant)
        if isinstance(plant, Tree):
            print(f"Added {plant.name} Tree to {self.owner}'s garden")
        else:
            print(f"Added {plant.name} to {self.owner}'s garden")

    def garden_report(self) -> None:
        """Generate the report of plants existing in selected garden"""
        print(f"=== {self.owner}'s Garden Report ===")
        print("Plants in garden")
        for _, plant in self.plants.items():
            if isinstance(plant, Tree):
                print(f" - {plant.name} Tree: {plant.height}cm")
            elif isinstance(plant, PrizeFlower):
                print(f" - {plant.name}: {plant.height}cm, " +
                      f"{plant.color} flowers (blooming), " +
                      f"Prize points: {plant.prize_points}")
            elif isinstance(plant, FloweringPlant):
                print(f" - {plant.name}: {plant.height}cm, " +
                      f"{plant.color} flowers (blooming)")
            else:
                print(f" - {plant.name}: {plant.height}cm")

    def get_score(self) -> int:
        """Generate garden score by multiplying number of trees with
           total growth since registry"""
        return (self.garden_stats.total_plants *
                self.garden_stats.get_plants_growth(self.plants))

    @classmethod
    def create_garden_network(cls, owners: list) -> list:
        """class method used to assign multiple gardens at
           once to garden registry"""
        all_owner = []
        for owner in owners:
            all_owner.append(cls(owner))
        return all_owner

    @staticmethod
    def validate_height(height: int) -> bool:
        """Static function which validate that height is positive"""
        return (height > 0)

    class GardenStats:
        """Nested helper class to analyze garden stats"""

        def __init__(self) -> None:
            self.total_plants = 0
            self.initial_len = 0
            self.regulars = 0
            self.flowers = 0
            self.prize_flowers = 0

        def add(self, plant: Plant) -> None:
            """With the new registry of plants, stats get updated"""
            self.total_plants += 1
            self.initial_len += plant.height
            if isinstance(plant, PrizeFlower):
                self.flowers += 1
            elif isinstance(plant, FloweringPlant):
                self.prize_flowers += 1
            else:
                self.regulars += 1

        def get_plants_growth(self, plants: dict) -> int:
            """Calculate total growth all all registered plants
               since the registry to garden manager"""
            current_len = 0
            for _, plant in plants.items():
                current_len += plant.height
            return (current_len - self.initial_len)

        def display_stats(self, plants: dict) -> None:
            """Display the current stats of the garden"""
            print(f"Plants added: {self.total_plants}, " +
                  f"Total growth: {self.get_plants_growth(plants)}cm")
            print(f"Plant Types: {self.regulars} regulars, {self.flowers} " +
                  f"flowering, {self.prize_flowers} prize flowers")


if __name__ == "__main__":
    print("=== Garden Management System Demo ===")
    print()
    alice = GardenManager("Alice")
    rose = FloweringPlant("Rose", 25, 30, "red color")
    sunflower = PrizeFlower("Sunflower", 50, 15, "yellow", 10)
    oak = Tree("Oak", 500, 1825, 50)
    alice.register_plant(oak)
    alice.register_plant(rose)
    alice.register_plant(sunflower)
    print()
    print("Alice is helping all plants grow...")
    alice.plants["Oak"].grow()
    alice.plants["Rose"].grow()
    alice.plants["Sunflower"].grow()
    print()
    alice.garden_report()
    print()
    alice.garden_stats.display_stats(alice.plants)
    print()
    bob = GardenManager("Bob")
    print("Height validation test: " +
          f"{GardenManager.validate_height(alice.plants['Oak'].height)}")
    print(f"Garden score - Alice: {alice.get_score()}, " +
          f"Bob: {bob.get_score()}")
    print(f"Total gardens managed: {GardenManager.total_gardens}")
    print()
    print("Garden Network example")
    print(f"Total gardens: {GardenManager.total_gardens}")
    all_owners = GardenManager.create_garden_network(['Owner1', 'Owner2'])
    print(f"New owners: {[owner.owner for owner in all_owners]}")
    print(f"Total gardens: {GardenManager.total_gardens}")
