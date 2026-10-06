#!/usr/bin/env/python3

from ex0 import FlameFactory, AquaFactory, CreatureFactory


def test_factory(factory: CreatureFactory) -> None:
    base_creature = factory.create_base()
    print(base_creature.describe())
    print(base_creature.attack())

    evolved_creature = factory.create_evolved()
    print(evolved_creature.describe())
    print(evolved_creature.attack())


def test_battle(factory1: CreatureFactory, factory2: CreatureFactory) -> None:
    creature_1 = factory1.create_base()
    creature_2 = factory2.create_base()

    print(creature_1.describe())
    print(" vs.")
    print(creature_2.describe())
    print(" fight!")
    print(creature_1.attack())
    print(creature_2.attack())


if __name__ == "__main__":
    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()

    print("Testing factory")
    test_factory(flame_factory)
    print("\nTesting battle")
    test_factory(aqua_factory)
    test_battle(flame_factory, aqua_factory)
