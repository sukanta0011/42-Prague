from .validator import validate_ingredients


def record_spell(spell_name: str, ingredients: str) -> str:
    validation_result = validate_ingredients(ingredients)
    result = validation_result.split("-")[1].strip()
    if result == "VALID":
        return f"Spell recorded: {spell_name} ({validation_result})"
    else:
        return f"Spell rejected: {spell_name} ({validation_result})"
