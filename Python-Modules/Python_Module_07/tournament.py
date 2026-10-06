#!/usr/bin/env/python3

from ex0 import FlameFactory, AquaFactory, CreatureFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import (
    BattleStrategy,
    NormalStrategy,
    AggressiveStrategy,
    DefensiveStrategy,
    InvalidStrategyError,
)


def battle(opponents: list[tuple[CreatureFactory, BattleStrategy]]) -> None:
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")

    creatures = [
        (factory.create_base(), strategy) for factory, strategy in opponents
        ]

    for i in range(len(creatures)):
        for j in range(i + 1, len(creatures)):
            creature1, strategy1 = creatures[i]
            creature2, strategy2 = creatures[j]

            print("\n* Battle *")
            print(creature1.describe())
            print(" vs.")
            print(creature2.describe())
            print(" now fight!")

            try:
                strategy1.act(creature1)
                strategy2.act(creature2)
            except InvalidStrategyError as i_s_e:
                print(f"Battle error, aborting tournament: {i_s_e}")
                return


if __name__ == "__main__":
    print("Tournament 0 (basic)")
    battle(
        [
            (FlameFactory(), NormalStrategy()),
            (HealingCreatureFactory(), DefensiveStrategy()),
        ]
    )

    print("\nTournament 1 (error)")
    battle(
        [
            (FlameFactory(), AggressiveStrategy()),
            (HealingCreatureFactory(), DefensiveStrategy()),
        ]
    )

    print("\nTournament 2 (multiple)")
    battle(
        [
            (AquaFactory(), NormalStrategy()),
            (HealingCreatureFactory(), DefensiveStrategy()),
            (TransformCreatureFactory(), AggressiveStrategy()),
        ]
    )
