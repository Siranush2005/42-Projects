def validate_ingredients(ingredients: str) -> str:
    from .light_spellbook import light_spell_allowed_ingredients

    allowed = light_spell_allowed_ingredients()

    for ingredient in ingredients.split(","):
        ingredient = ingredient.strip().lower()

        if ingredient in allowed:
            return "VALID " + ingredients

    return "INVALID " + ingredients
