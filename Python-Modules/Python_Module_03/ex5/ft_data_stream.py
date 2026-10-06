#!/usr/bin/env python3

from typing import Generator
import random


players = ["alice", "bob", "charlie", "dylan"]

actions = [
    "run",
    "eat",
    "sleep",
    "grab",
    "move",
    "climb",
    "swim",
    "release",
    "use",
]


def gen_event() -> Generator[tuple[str, str], None, None]:
    while True:
        player = random.choice(players)
        action = random.choice(actions)
        yield player, action


def consume_event(
    events: list[tuple[str, str]],
) -> Generator[tuple[str, str], None, None]:
    while len(events) > 0:
        i = random.randint(0, len(events) - 1)
        event = events[i]
        events[:] = events[:i] + events[i + 1:]
        yield event


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")

    g = gen_event()

    for i in range(1000):
        player, action = next(g)
        print(f"Event {i}: Player {player} did action {action}")

    events = []
    for _ in range(10):
        events += [next(g)]

    print(f"Built list of 10 events: {events}")

    for event in consume_event(events):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {events}")
