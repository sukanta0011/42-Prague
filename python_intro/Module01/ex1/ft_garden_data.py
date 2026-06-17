class Plant:
    """A class to represents plants in the garden"""
    def __init__(self, name: str, height: int, age: int) -> None:
        """Initialize the plant with name, height and name"""
        self.name = name
        self.height = height
        self.plant_age = age


if __name__ == "__main__":
    print("=== Garden Plant Registry ===")
    rose = Plant("Rose", 25, 30)
    sn_flower = Plant("Sunflower", 80, 45)
    cactus = Plant("Cactus", 15, 120)
    print(f"{rose.name}: {rose.height}cm, {rose.plant_age} days old")
    print(f"{sn_flower.name}: {sn_flower.height}cm, {sn_flower.plant_age} " +
          "days old")
    print(f"{cactus.name}: {cactus.height}cm, {cactus.plant_age} days old")
