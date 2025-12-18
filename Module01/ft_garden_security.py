class SecurePlant:
    """A class representing SecurePlants in garden community registry"""

    def __init__(self, name: str) -> None:
        """Initialize a new plant with the name and declare after creation"""
        self.__name = name
        self.__height = 0
        self.__plant_age = 0
        print("Plant created:", self.__name)

    def set_height(self, height: int) -> None:
        """Verify and set the heigh of the plant"""
        if (height >= 0):
            self.__height = height
            print(f"Height updated: {height}cm [OK]")
        else:
            print(f"Invalid operation attempted: height {height}cm [REJECTED]")
            print("Security: Negative height rejected")

    def set_age(self, age: int) -> None:
        """Verify and set the age of the plant"""
        if (age >= 0):
            self.__plant_age = age
            print(f"Height updated: {age}cm [OK]")
        else:
            print(f"Invalid operation attempted: height {age}cm [REJECTED]")
            print("Security: Negative height rejected")

    def get_name(self) -> str:
        """Return the name of the plant"""
        return (self.__name)

    def get_height(self) -> int:
        """Return the height of the plant"""
        if self.__height == 0:
            print(f"Height of {self.__name} is not set yet!!")
        return (self.__height)

    def get_age(self) -> int:
        """Return the age of the plant"""
        if self.__plant_age == 0:
            print(f"Age of {self.__name} is not set yet!!")
        return (self.__plant_age)


print("===  Garden Security System ===")
rose = SecurePlant("Rose")
print(f"Current plant: {rose.get_name()}" +
      f"({rose.get_height()}cm, {rose.get_age()} days)")
rose.set_age(30)
rose.set_height(10)
rose.set_height(-1)
print(f"Current plant: {rose.get_name()}" +
      f"({rose.get_height()}cm, {rose.get_age()} days)")
