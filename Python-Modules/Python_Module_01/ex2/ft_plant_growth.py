#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age_days = age
        self.growth_rate = 0.8

    def grow(self) -> None:
        self.height += self.growth_rate

    def age(self) -> None:
        self.age_days += 1

    def show(self) -> None:
        print(f"{self.name}: {self.height:.1f}cm, {self.age_days} days old")


if __name__ == "__main__":
    print("=== Garden Plant Growth ===")

    plant = Plant("Rose", 25.0, 30)

    plant.show()

    initial_height = plant.height

    for day in range(1, 8):
        plant.grow()
        plant.age()

        print(f"=== Day {day} ===")
        plant.show()

    growth = plant.height - initial_height

    print(f"Growth this week: {growth:.1f}cm")
