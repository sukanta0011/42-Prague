class Plant:
    """A class to represents plants in the garden"""
    def __init__(self, name: str, height: int, age: int) -> None:
        """Initialize the plant with name, height and name"""
        self.name = name
        self.height = height
        self.plant_age = age

    def get_info(self) -> str:
        """Return plant information in structured way"""
        return f"{self.name}: {self.height}cm, {self.plant_age} days old"

    def grow(self, growth_rate: int = 1) -> None:
        """Increase the plant height by growth rate per day"""
        self.height += growth_rate

    def age(self) -> None:
        """Increase the plant age by a day"""
        self.plant_age += 1


if __name__ == "__main__":
    rose = Plant("Rose", 25, 30)
    sn_flower = Plant("Sunflower", 80, 45)
    rose_initial_height = 0
    rose_final_height = 0
    sn_flower_initial_height = 0
    sn_flower_final_height = 0

    days = 7
    for i in range(1, days + 1):
        rose.age()
        rose.grow()
        sn_flower.age()
        sn_flower.grow(2)
        if (i == 1):
            print(f"\n=== Day {i} ===")
            print(rose.get_info())
            print(sn_flower.get_info())
            rose_initial_height = rose.height
            sn_flower_initial_height = sn_flower.height
        if (i == days):
            print(f"\n=== Day {i} ===")
            print(rose.get_info())
            print(sn_flower.get_info())
            rose_final_height = rose.height
            sn_flower_final_height = sn_flower.height

    print("\n=== Growth Summary ===")
    print("Growth this week, Rose: " +
          f"+{rose_final_height - rose_initial_height}cm")
    print("Growth this week, Sunflower: " +
          f"+{sn_flower_final_height - sn_flower_initial_height}cm")
