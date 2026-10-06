from ex0.creature import Creature
from ex1.capability import HealCapability, TransformCapability
from .strategy import BattleStrategy, InvalidStrategyError


class NormalStrategy(BattleStrategy):
    def act(self, creature: Creature) -> None:
        print(creature.attack())

    def is_valid(self, creature: Creature) -> bool:
        return True


class AggressiveStrategy(BattleStrategy):
    def act(self, creature: Creature) -> None:
        # self.is_valid(creature) is not used because mypy raises an error.
        # Mypy checks each function independently and does not infer that
        # creature has the required attributes after calling is_valid().
        # It does not inspect is_valid() first and then validate the
        # not act case.
        if not isinstance(creature, TransformCapability):
            raise InvalidStrategyError(
                f"Invalid Creature '{creature.name}' "
                "for this aggressive strategy"
            )
        print(creature.transform())
        print(creature.attack())
        print(creature.revert())

    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, TransformCapability)


class DefensiveStrategy(BattleStrategy):
    def act(self, creature: Creature) -> None:
        if not isinstance(creature, HealCapability):
            raise InvalidStrategyError(
                f"Invalid Creature '{creature.name}' "
                "for this defensive strategy"
            )
        print(creature.attack())
        print(creature.heal())

    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, HealCapability)
