def mage_counter() -> callable:
    counter = 0

    def mage_counter():
        nonlocal counter
        counter += 1
        return counter
    return mage_counter


def spell_accumulator(initial_power: int) -> callable:
    total_power = initial_power

    def add_power(power: int):
        nonlocal total_power
        total_power += power
        return total_power
    return add_power


def enchantment_factory(enchantment_type: str) -> callable:
    def add_enhancement(item: str):
        nonlocal enchantment_type
        return f"{enchantment_type} {item}"
    return add_enhancement


def memory_vault() -> dict[str, callable]:
    storage = {}

    def store(key: str, val: str):
        nonlocal storage
        storage[key] = val

    def recall(key: str):
        nonlocal storage
        if key in storage.keys():
            return storage[key]
        else:
            return "Memory not found"
    return {"store": store,
            "recall": recall}


if __name__ == "__main__":
    initial_powers = [60, 27, 73]
    power_additions = [17, 17, 8, 8, 19]
    enchantment_types = ['Shocking', 'Dark', 'Flaming']
    items_to_enchant = ['Sword', 'Cloak', 'Ring', 'Shield']

    print("Testing mage counter...")
    caller = mage_counter()
    for i in range(5):
        print(f"Call {i +1}: {caller()}")
    print()
    print("Testing power addition...")
    final_power = spell_accumulator(0)
    for power in power_additions:
        print(f"Power {power} added: {final_power(power)}")
    print()
    print("Testing enchantment factory...")
    enhance_item = enchantment_factory("Flaming")
    print(enhance_item("Sword"))
    enhance_item = enchantment_factory("Frozen")
    print(enhance_item("Shield"))
    print()
    print("Testing memory vault...")
    vault = memory_vault()
    # print(vault['recall']('sword'))
    vault['store']("sword", 2)
    vault['store']("shield", 1)
    print(f"Swords: {vault['recall']('sword')}")
    print(f"Bows: {vault['recall']('bow')}")
