from .light_validator import validate_ingredients


def light_spell_allowed_ingredients() -> list[str]:
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    decision = validate_ingredients(ingredients)
    if decision[:5] == "VALID":
        return f"Spell recorded: {spell_name} ({ingredients} - VALID)"
    return f"Spell recorded: {spell_name} ({ingredients} - INVALID)"
