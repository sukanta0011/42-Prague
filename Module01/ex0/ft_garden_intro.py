def ft_garden_intro(name: str, height: int, age: int) -> None:
    """Take input from the uer and print formatted output"""
    print("Plant:", name)
    print(f"Height: {height}cm")
    print(f"Age: {age} days")


if __name__ == "__main__":
    print("=== Welcome to My Garden ===")
    ft_garden_intro("Rose", 25, 30)
    print("\n=== End of Program ===")
