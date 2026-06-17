from abc import ABC, abstractmethod


class Card(ABC):
    """Abstract base class of Cards"""

    def __init__(self, name: str, cost: int, rarity: str):
        self.name = name
        self.cost = cost
        self.rarity = rarity

    @abstractmethod
    def play(self, game_state: dict) -> dict:
        pass

    def get_card_info(self) -> dict:
        return {
            "Name": self.name,
            "Cost": self.cost,
            "Rarity": self.rarity,
            }

    def is_playable(self, available_mana: int):
        return available_mana >= self.cost
