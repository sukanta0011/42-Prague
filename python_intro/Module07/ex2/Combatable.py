from abc import ABC, abstractmethod


class Combatable(ABC):
    def __init__(self, combat_type: str, damage: str,
                 health: int, shield: int) -> None:
        self.combat_type = combat_type
        self.damage = damage
        self.health = health
        self.shield = shield

    @abstractmethod
    def attack(self, target: str) -> dict:
        pass

    @abstractmethod
    def defend(self, incoming_damage: int) -> dict:
        pass

    @abstractmethod
    def get_combat_stats(self) -> dict:
        pass
