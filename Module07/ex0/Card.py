from abc import ABC, abstractmethod


class Card(ABC):
    """Abstract base class of Cards"""

    def __init__(self, name: str, cost: int, rarity: str):
        self.name = name
        self.cost = cost
        self.rarity = rarity

    @abstractmethod
    def play(self, game_state: dict):
        pass

    def get_card_info(self):
        return f"Name: {self.name}, Cost: {self.cost} "\
               f"Rarity: {self.rarity}"

    def is_playable(self, abailable_mana: int):
        return abailable_mana >= self.cost
