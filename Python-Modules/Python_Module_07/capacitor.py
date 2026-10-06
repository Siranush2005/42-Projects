#!/usr/bin/env/python3

from ex1 import HealingCreatureFactory, TransformCreatureFactory


def test_healing_creature(factory: HealingCreatureFactory) -> None:
    print(" base:")
    creature = factory.create_base()
    print(creature.describe())
    print(creature.attack())
    print(creature.heal())

    print(" evolved:")
    creature = factory.create_evolved()
    print(creature.describe())
    print(creature.attack())
    print(creature.heal())


def test_transform_creature(factory: TransformCreatureFactory) -> None:
    print(" base:")
    creature = factory.create_base()
    print(creature.describe())
    print(creature.attack())
    print(creature.transform())
    print(creature.attack())
    print(creature.revert())

    print(" evolved:")
    creature = factory.create_evolved()
    print(creature.describe())
    print(creature.attack())
    print(creature.transform())
    print(creature.attack())
    print(creature.revert())


if __name__ == "__main__":
    print("Testing Creature with healing capability")
    test_healing_creature(HealingCreatureFactory())

    print("\nTesting Creature with transform capability")
    test_transform_creature(TransformCreatureFactory())
