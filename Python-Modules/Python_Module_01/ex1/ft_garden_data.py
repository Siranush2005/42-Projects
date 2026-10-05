#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age} days old")


if __name__ == "__main__":
    print("=== Garden Plant Registry ===")

    plant1 = Plant("Rose", 25, 30)
    plant2 = Plant("Sunflower", 80, 45)
    plant3 = Plant("Cactus", 15, 120)

    plant1.show()
    plant2.show()
    plant3.show()

# class Plant:
#     def show(self) -> None:
#         print(f"{self.name}: {self.height}cm, {self.age} days old")

# if __name__ == "__main__":
#     print("=== Garden Plant Registry ===")

#     plant1 = Plant()
#     plant1.name = "Rose"
#     plant1.height = 25
#     plant1.age = 30

#     plant2 = Plant()
#     plant2.name = "Sunflower"
#     plant2.height = 80
#     plant2.age = 45

#     plant3 = Plant()
#     plant3.name = "Cactus"
#     plant3.height = 15
#     plant3.age = 120

#     plant1.show()
#     plant2.show()
#     plant3.show()
