#!/usr/bin/env python3

import math


def get_player_pos() -> tuple[float, float, float]:
    while True:
        pos = input("Enter new coordinates as floats in format 'x,y,z': ")

        try:
            coordinates = pos.split(",")

            coord_len = 0
            for c in coordinates:
                coord_len += 1

            if coord_len == 3:
                x = float(coordinates[0])
                y = float(coordinates[1])
                z = float(coordinates[2])
                return (x, y, z)
            else:
                print("Invalid syntax!")
                continue
        except ValueError as e:
            msg = e.args[0]
            print(f"Error on parameter {msg.split(':')[-1].strip()}: {msg}")


def coord_distance(
                    p1: tuple[float, float, float],
                    p2: tuple[float, float, float]) -> float:
    return math.sqrt(
        (p2[0] - p1[0]) ** 2 +
        (p2[1] - p1[1]) ** 2 +
        (p2[2] - p1[2]) ** 2
    )


if __name__ == "__main__":
    print("=== Game Coordinate System ===\n")

    print("Get a first set of coordinates")
    p1 = get_player_pos()

    print(f"Got a first tuple: {p1}")
    print(f"It includes: X={p1[0]}, Y={p1[1]}, Z={p1[2]}")

    print("Distance to center:", end=" ")
    print(f"{round(coord_distance(p1, (0.0, 0.0, 0.0)), 4)}")

    print("\nGet a second set of coordinates")
    p2 = get_player_pos()

    print("Distance between the 2 sets of coordinates :", end=" ")
    print(f"{round(coord_distance(p1, p2), 4)}")
