from ex0.creature import Creature
from .capability import TransformCapability


class TransformingCreature(Creature, TransformCapability):
    pass


class Shiftling(TransformingCreature):
    def __init__(
        self, name: str = "Shiftling", creature_type: str = "Normal"
    ) -> None:
        super().__init__(name, creature_type)

    def transform(self) -> str:
        self.is_transformed = True
        return "Shiftling shifts into a sharper form!"

    def revert(self) -> str:
        self.is_transformed = False
        return "Shiftling returns to normal."

    def attack(self) -> str:
        if self.is_transformed:
            return "Shiftling performs a boosted strike!"
        return "Shiftling attacks normally."


class Morphagon(TransformingCreature):
    def __init__(
        self, name: str = "Morphagon", creature_type: str = "Normal/Dragon"
    ) -> None:
        super().__init__(name, creature_type)

    def transform(self) -> str:
        self.is_transformed = True
        return "Morphagon morphs into a dragonic battle form!"

    def revert(self) -> str:
        self.is_transformed = False
        return "Morphagon stabilizes its form."

    def attack(self) -> str:
        if self.is_transformed:
            return "Morphagon unleashes a devastating morph strike!"
        return "Morphagon attacks normally."
