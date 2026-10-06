from ex0.creature import Creature
from .capability import HealCapability


class HealingCreature(Creature, HealCapability):
    pass


class Sproutling(HealingCreature):
    def __init__(
        self, name: str = "Sproutling", creature_type: str = "Grass"
    ) -> None:
        super().__init__(name, creature_type)

    def attack(self) -> str:
        return "Sproutling uses Vine Whip!"

    def heal(self) -> str:
        return "Sproutling heals itself for a small amount"


class Bloomelle(HealingCreature):
    def __init__(
        self, name: str = "Bloomelle", creature_type: str = "Grass/Fairy"
    ) -> None:
        super().__init__(name, creature_type)

    def attack(self) -> str:
        return "Bloomelle uses Petal Dance!"

    def heal(self) -> str:
        return "Bloomelle heals itself and others for a large amount"
