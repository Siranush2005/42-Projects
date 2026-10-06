from .dark_validator import validate_ingredients


def dark_spell_allowed_ingredients() -> list[str]:
    return ["bats", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: str) -> str:
    decision = validate_ingredients(ingredients)
    if decision[:5] == "VALID":
        return "Spell recorded: " + f"{ingredients}"
    return "Spell rejected: " + f"{ingredients}"
