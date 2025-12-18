class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.plant_age = age

    def get_info(self) -> str:
        return f"{self.name}: {self.height}cm, {self.plant_age} days old"

    def grow(self, growth_rate: int = 1) -> None:
        self.height += growth_rate

    def age(self) -> None:
        self.plant_age += 1


rose = Plant("Rose", 25, 30)
sn_flwr = Plant("Sunflower", 80, 45)
rose_initial_height = 0
rose_final_height = 0
sn_flwr_initial_height = 0
sn_flwr_final_height = 0

days = 7
for i in range(1, days + 1):
    print(f"\n=== Day {i} ===")
    rose.age()
    rose.grow()
    print(rose.get_info())
    sn_flwr.age()
    sn_flwr.grow(2)
    print(sn_flwr.get_info())
    if (i == 1):
        rose_initial_height = rose.height
        sn_flwr_initial_height = sn_flwr.height
    if (i == days):
        rose_final_height = rose.height
        sn_flwr_final_height = sn_flwr.height

print("\n=== Growth Summary ===")
print(f"Growth this week, Rose: +{rose_final_height - rose_initial_height}cm")
print("Growth this week, Sunflower: " +
      f"+{sn_flwr_final_height - sn_flwr_initial_height}cm")
