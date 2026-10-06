#!/usr/bin/env python3

import random

achievements = [
    "Crafting Genius",
    "World Savior",
    "Master Explorer",
    "Collector Supreme",
    "Untouchable",
    "Boss Slayer",
    "Strategist",
    "Unstoppable",
    "Speed Runner",
    "Survivor",
    "Treasure Hunter",
    "First Steps",
    "Sharp Mind",
    "Hidden Path Finder",
    "Legendary Builder",
    "Dungeon Conqueror",
    "Puzzle Master",
    "Stealth Expert",
    "Resource Hoarder",
    "Ultimate Survivor"
]


def gen_player_achievements() -> set[str]:
    achievements_count = random.randint(1, len(achievements))
    return set(random.sample(achievements, achievements_count))


if __name__ == "__main__":
    print("=== Achievement Tracker System ===\n")

    # or Players_list: list[set] = [Alice, Bob, Charlie, Dylan]
    Alice = gen_player_achievements()
    Bob = gen_player_achievements()
    Charlie = gen_player_achievements()
    Dylan = gen_player_achievements()

    print(f"Player Alice: {Alice}")
    print(f"Player Bob: {Bob}")
    print(f"Player Charlie: {Charlie}")
    print(f"Player Dylan: {Dylan}")

    print()

    distinct = set.union(Alice, Bob, Charlie, Dylan)
    print(f"All distinct achievements: {distinct}")

    common = set.intersection(Alice, Bob, Charlie, Dylan)
    print(f"Common achievements: {common}")

    # I can do it this way
    # print("Common achievements:", end=" ")
    # print(f"{Alice & Bob & Charlie & Dylan}")

    print()

    print(f"Only Alice has: {Alice - (Bob | Charlie | Dylan)}")
    print(f"Only Bob has: {Bob - (Alice | Charlie | Dylan)}")
    print(f"Only Charlie has: {Charlie - (Alice | Bob | Dylan)}")
    print(f"Only Dylan has: {Dylan - (Alice | Bob | Charlie)}")

    print()

    print(f"Alice is missing: {distinct - Alice}")
    print(f"Bob is missing: {distinct - Bob}")
    print(f"Charlie is missing: {distinct - Charlie}")
    print(f"Dylan is missing: {distinct - Dylan}")
