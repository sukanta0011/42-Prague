class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.plant_age = age


print("=== Garden Plant Registry ===")
rose = Plant("Rose", 25, 30)
sn_flwr = Plant("Sunflower", 80, 45)
cactus = Plant("Cactus", 15, 120)
print(f"{rose.name}: {rose.height}cm, {rose.plant_age} days old")
print(f"{sn_flwr.name}: {sn_flwr.height}cm, {sn_flwr.plant_age} days old")
print(f"{cactus.name}: {cactus.height}cm, {cactus.plant_age} days old")
