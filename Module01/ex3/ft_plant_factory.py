class Plant:
    """A class representing the community garden registry"""

    def __init__(self, name: str, height: int, age: int) -> None:
        """
        Initializing the new plant with name, age, height and
        self declaration after creation.
        """
        self.name = name
        self.height = height
        self.plant_age = age
        print(f"Created: {self.name} ({self.height}cm, {self.plant_age} days)")

    def get_info(self) -> None:
        """
        Get the current state of the plant.
        """
        print(f"{self.name}: {self.height}cm, {self.plant_age} days old")

    def grow(self, growth_rate: int = 1) -> None:
        """
        Increase the plant height by growth rate.
        """
        self.height += growth_rate

    def age(self) -> None:
        """
        Increase the plant age by a day.
        """
        self.plant_age += 1


if __name__ == "__main__":
    print("=== Plant Factory Output ===")
    rose = Plant("Rose", 25, 30)
    oak = Plant("Oak", 200, 365)
    cactus = Plant("Cactus", 15, 120)
    sn_flower = Plant("Sunflower", 80, 45)
    fern = Plant("Fern", 15, 120)

    print("\nTotal plants created: 5")
