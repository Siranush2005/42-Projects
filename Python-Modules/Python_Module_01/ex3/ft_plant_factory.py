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
    print("=== Plant Factory Output ===")

    plant_list = [
            Plant("Rose", 25.0, 30),
            Plant("Oak", 200.0, 365),
            Plant("Cactus", 5.0, 90),
            Plant("Sunflower", 80.0, 45),
            Plant("Fern", 15.0, 120)
    ]

    for plant in plant_list:
        print("Created: ", end="")
        plant.show()
