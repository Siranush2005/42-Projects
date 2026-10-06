#!/usr/bin/env python3

import random

if __name__ == "__main__":
    print("=== Game Data Alchemist ===\n")

    initial_list = [
        'Alice', 'bob', 'Charlie', 'dylan',
        'Emma', 'Gregory', 'john', 'kevin', 'Liam'
    ]

    print(f"Initial list of players: {initial_list}")

    new_list = [name.capitalize() for name in initial_list]
    print(f"New list with all names capitalized: {new_list}")

    only_capitalized = [name for name in initial_list if name[0].isupper()]
    print(f"New list of capitalized names only: {only_capitalized}")

    score_dict = {name: random.randint(1, 1000) for name in new_list}
    print(f"\nScore dict: {score_dict}")

    total_scores = sum([score_dict[name] for name in new_list])
    avg_score = round(total_scores / len(new_list), 2)
    print(f"Score average is {avg_score}")

    high_scores = {
        name: score_dict[name]
        for name in new_list
        if score_dict[name] > avg_score
    }

    print(f"High scores: {high_scores}")
