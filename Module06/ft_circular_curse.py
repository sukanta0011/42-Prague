from alchemy.grimoire.validator import validate_ingredients
from alchemy.grimoire.spellbook import record_spell


if __name__ == "__main__":
    print("Testing ingredient validation:")
    print()
    print("validate_ingredients(\"fire air\"): " +
          f"{validate_ingredients('fire air')}")
    print("validate_ingredients(\"dragon scales\"): " +
          f"{validate_ingredients('dragon scales')}")

    print()
    print("Testing spell recording with validation:")
    print("record_spell(\"Fireball\", \"fire air\"): " +
          f"{record_spell('Fireball', 'fire air')}")
    print("record_spell(\"Dark Magic\", \"shadow\"): " +
          f"{record_spell('Dark Magic', 'shadow')}")

    print()
    print("Testing late import technique:")
    from alchemy.grimoire.spellbook import record_spell
    print("record_spell(\"Lightning\", \"air\"): " +
          f"{record_spell('Lightning', 'air')}")

    print()
    print("Circular dependency curse avoided using late imports!")
    print("All spells processed safely!")
