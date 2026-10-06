#!/usr/bin/env python3

class GardenError(Exception):
    def __init__(self, error_msg: str = "Unknown garden error") -> None:
        super().__init__(error_msg)


class PlantError(GardenError):
    def __init__(self, error_msg: str = "Unknown plant error") -> None:
        super().__init__(error_msg)


class WaterError(GardenError):
    def __init__(self, error_msg: str = "Unknown water error") -> None:
        super().__init__(error_msg)


def check_plant() -> None:
    raise PlantError("The tomato plant is wilting!")


def check_water() -> None:
    raise WaterError("Not enough water in the tank!")


def test_specific_errors() -> None:
    print("Testing PlantError...")
    try:
        check_plant()
    except PlantError as error:
        print(f"Caught PlantError: {error}")

    print("\nTesting WaterError...")
    try:
        check_water()
    except WaterError as error:
        print(f"Caught WaterError: {error}")


def test_garden_error() -> None:
    print("\nTesting catching all garden errors...")

    try:
        check_plant()
    except GardenError as error:
        print(f"Caught GardenError: {error}")

    try:
        check_water()
    except GardenError as error:
        print(f"Caught GardenError: {error}")


if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===\n")

    test_specific_errors()
    test_garden_error()

    print("\nAll custom error types work correctly!")
