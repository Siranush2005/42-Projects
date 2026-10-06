from .dark_spellbook import dark_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:

    allowed = dark_spell_allowed_ingredients()

    for ingredient in ingredients.split(","):
        ingredient = ingredient.strip().lower()

        if ingredient in allowed:
            return "VALID " + ingredients

    return "INVALID " + ingredients
