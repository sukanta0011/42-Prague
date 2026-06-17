def validate_ingredients(ingredients: str) -> str:
    """Validate the list of ingredients"""
    valid_ingredients = ["fire", "water", "earth", "air"]
    ingredient_list = ingredients.split(" ")

    for ingredient in ingredient_list:
        if ingredient not in valid_ingredients:
            return f"{ingredients} - INVALID"
    return f"{ingredients} - VALID"


def late_recorded_spell(spell_name: str, ingredients: str) -> str:
    """Demonstrating late import"""
    from .spellbook import record_spell
    return record_spell(spell_name, ingredients)
