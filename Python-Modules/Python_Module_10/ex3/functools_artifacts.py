#!/usr/bin/env python3

import functools
import operator
from collections.abc import Callable
from typing import Any


def spell_reducer(spells: list[int], operation: str) -> int:
    operations = ["min", "max", "multiply", "add"]

    if not spells:
        return 0

    if operation not in operations:
        raise ValueError(f"Unknown operation: {operation}")

    def max_function(x: int, y: int) -> int:
        return max(x, y)

    def min_function(x: int, y: int) -> int:
        return min(x, y)

    operations_dict = {
        "add": operator.add,
        "multiply": operator.mul,
        "max": max_function,
        "min": min_function
    }
    return functools.reduce(operations_dict[operation], spells)


def base_enchantment(power: int, element: str, target: str) -> str:
    return f"{element} spell on {target}: {power}"


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:
    fire_spell = functools.partial(
        base_enchantment, power=50, element="fire"
    )
    ice_spell = functools.partial(
        base_enchantment, power=50, element="ice"
    )
    lightning_spell = functools.partial(
        base_enchantment, power=50, element="lightning"
    )

    return {
        "fire_enchant": fire_spell,
        "ice_enchant": ice_spell,
        "lightning_enchant": lightning_spell,
    }


@functools.lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    if n < 2:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:

    @functools.singledispatch
    def spell_cast(spell: Any) -> str:
        return "Unknown spell type"

    @spell_cast.register
    def _(spell: int) -> str:
        return f"Damage spell: {spell} damage"

    @spell_cast.register
    def _(spell: str) -> str:
        return f"Enchantment: {spell}"

    @spell_cast.register
    def _(spell: list) -> str:
        return f"Multi-cast: {len(spell)} spells"

    return spell_cast


if __name__ == "__main__":
    print("Testing spell reducer...")
    add_result = spell_reducer([90, -10, 15, 5], "add")
    mult_result = spell_reducer([10, -6, 20, -200], "multiply")
    max_result = spell_reducer([10, -23, 0, 40], "max")
    print(f"Sum: {add_result}")
    print(f"Product: {mult_result}")
    print(f"Max: {max_result}")

    print("\nTesting partial enchanter...")
    spells = partial_enchanter(base_enchantment)
    print(spells["fire_enchant"](target="goblin"))
    print(spells["ice_enchant"](target="dragon"))

    print("\nTesting memoized fibonacci...")
    print(f"Fib(0): {memoized_fibonacci(0)}")
    print(f"Fib(1): {memoized_fibonacci(1)}")
    print(f"Fib(10): {memoized_fibonacci(10)}")
    print(f"Fib(15): {memoized_fibonacci(15)}")
    print(memoized_fibonacci.cache_info())

    print("\nTesting spell dispatcher...")
    dispatch = spell_dispatcher()
    print(dispatch(42))
    print(dispatch("fireball"))
    print(dispatch([10, 20, 30]))
    print(dispatch(3.14))
