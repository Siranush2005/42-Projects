#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self._height = 0.0
        self._age_days = 0

        if height >= 0:
            self._height = height
        else:
            print(f"{self.name}: Error, height can't be negative")

        if age >= 0:
            self._age_days = age
        else:
            print(f"{self.name}: Error, age can't be negative")

    def set_height(self, height: float) -> None:
        if height < 0:
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = height
            print(f"Height updated: {height:g}")

    def set_age(self, age: int) -> None:
        if age < 0:
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age_days = age
            print(f"Age updated: {age}")

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age_days

    def grow(self) -> None:
        self._height += 0.8

    def age(self) -> None:
        self._age_days += 1

    def show(self) -> None:
        print(f"{self.name}: {self._height:.1f}cm, {self._age_days} days old")


if __name__ == "__main__":
    print("=== Garden Security System ===")

    plant = Plant("Rose", 15.0, 10)

    print("Plant created:", end=" ")
    plant.show()
    print()
    plant.set_height(25)
    plant.set_age(30)
    print()
    plant.set_height(-5)
    plant.set_age(-10)

    print("Current state:", end=" ")
    plant.show()
