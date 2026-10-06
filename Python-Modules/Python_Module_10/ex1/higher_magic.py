#!/usr/bin/env python3

from collections.abc import Callable
from typing import Any


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    def combined_spell(*args: Any, **kwargs: Any) -> tuple[Any, Any]:
        result_1 = spell1(*args, **kwargs)
        result_2 = spell2(*args, **kwargs)
        return (result_1, result_2)

    return combined_spell


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    def amplified_spell(*args: Any, **kwargs: Any) -> Any:
        if not args:
            raise ValueError("No arguments provided to the spell.")
        amplified_args = (*args[:-1], args[-1] * multiplier)
        return base_spell(*amplified_args, **kwargs)

    return amplified_spell


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    def conditional_spell(*args: Any, **kwargs: Any) -> Any:
        if not condition(*args, **kwargs):
            return "Spell fizzled"
        return spell(*args, **kwargs)

    return conditional_spell


def spell_sequence(spells: list[Callable]) -> Callable:
    def sequence_spell(*args: Any, **kwargs: Any) -> list[Any]:
        results: list[Any] = []

        for spell in spells:
            results.append(spell(*args, **kwargs))

        return results

    return sequence_spell


if __name__ == "__main__":
    print("Testing spell combiner...")

    def fireball(target: str) -> str:
        return f"Fireball hits {target}"

    def heal(target: str) -> str:
        return f"Heals {target}"

    combined_spell = spell_combiner(fireball, heal)
    result = combined_spell("Dragon")
    print(f"Combined spell result: {result[0]}, {result[1]}")

    print("\nTesting power amplifier...")

    def base_spell(power: int) -> int:
        return power

    amplified_spell = power_amplifier(base_spell, 3)
    original_power = 10
    amplified_power = amplified_spell(original_power)

    print(
        f"Original: {original_power}, "
        f"Amplified: {amplified_power}"
    )
