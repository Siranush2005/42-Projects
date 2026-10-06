#!/usr/bin/env python3

from collections.abc import Callable
from typing import Any


def mage_counter() -> Callable:
    count = 0

    def counter_function() -> int:
        nonlocal count
        count += 1
        return count
    return counter_function


def spell_accumulator(initial_power: int) -> Callable:
    def power_accumulator(power_to_be_added: int) -> int:
        nonlocal initial_power
        initial_power += power_to_be_added
        return initial_power
    return power_accumulator


def enchantment_factory(enchantment_type: str) -> Callable:
    def apply_enchantment(item: str) -> str:
        return enchantment_type + " " + item
    return apply_enchantment


def memory_vault() -> dict[str, Callable]:
    memory_dict: dict[Any, Any] = {}

    def store(key: Any, value: Any) -> None:
        memory_dict[key] = value

    def recall(key: Any) -> Any:
        if key in memory_dict:
            return memory_dict[key]
        return "Memory not found"

    return {"store": store, "recall": recall}


if __name__ == "__main__":

    print("Testing mage counter...")
    counter_a = mage_counter()
    print(f"counter_a call 1: {counter_a()}")
    print(f"counter_a call 2: {counter_a()}")
    counter_b = mage_counter()
    print(f"counter_b call 1: {counter_b()}")

    print("\nTesting spell accumulator...")
    p_a = spell_accumulator(100)
    print("Base 100, add 20: ", p_a(20))
    print("Base 100, add 30: ", p_a(30))

    print("\nTesting enchantment factory...")
    factory_1 = enchantment_factory("Flaming")
    print(factory_1("Sword"))
    factory_2 = enchantment_factory("Frozen")
    print(factory_2("Shield"))

    print("\nTesting memory vault...")
    vault = memory_vault()
    print("Store 'secret' = 42")
    vault["store"]("secret", 42)
    print("Recall 'secret':", vault["recall"]("secret"))
    print("Recall 'unknown':", vault["recall"]("unknown"))
