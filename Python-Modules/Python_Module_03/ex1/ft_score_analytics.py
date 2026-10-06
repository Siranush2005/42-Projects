#!/usr/bin/env python3

import sys


def get_score_list(score_lst: list[str]) -> list[int]:
    scores: list[int] = []

    for num in score_lst:
        try:
            scores += [int(num)]
        except ValueError:
            print(f"Invalid parameter: '{num}'")
    return scores


if __name__ == "__main__":
    if len(sys.argv) == 1:
        print("No scores provided.", end=" ")
        print("Usage: python3 ft_score_analytics.py <score1> <score2> ...")
    else:
        scores = get_score_list(sys.argv[1:])

        if len(scores) == 0:
            print("No scores provided.", end=" ")
            print("Usage: python3 ft_score_analytics.py <score1> <score2> ...")
        else:
            print(f"Scores processed: {scores}")
            print(f"Total players: {len(scores)}")
            print(f"Total score: {sum(scores)}")
            print(f"Average score: {sum(scores) / len(scores)}")
            print(f"High score: {max(scores)}")
            print(f"Low score: {min(scores)}")
            print(f"Score range: {max(scores) - min(scores)}")

# The 24th line is there in case all the arguments are invalid
