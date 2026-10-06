from abc import ABC, abstractmethod


class Creature(ABC):
    def __init__(self, name: str, creature_type: str) -> None:
        self.name = name
        self.creature_type = creature_type
        super().__init__()

    @abstractmethod
    def attack(self) -> str:
        pass

    def describe(self) -> str:
        return f"{self.name} is a {self.creature_type} type Creature"


class Flameling(Creature):
    def __init__(
        self, name: str = "Flameling", creature_type: str = "Fire"
    ) -> None:
        super().__init__(name, creature_type)

    def attack(self) -> str:
        return "Flameling uses Ember!"


class Pyrodon(Creature):
    def __init__(
        self, name: str = "Pyrodon", creature_type: str = "Fire"
    ) -> None:
        super().__init__(name, creature_type)

    def attack(self) -> str:
        return "Pyrodon uses Flamethrower!"


class Aquabub(Creature):
    def __init__(
        self, name: str = "Aquabub", creature_type: str = "Water"
    ) -> None:
        super().__init__(name, creature_type)

    def attack(self) -> str:
        return "Aquabub uses Water Gun!"


class Torragon(Creature):
    def __init__(
        self, name: str = "Torragon", creature_type: str = "Water"
    ) -> None:
        super().__init__(name, creature_type)

    def attack(self) -> str:
        return "Torragon uses Hydro Pump!"
