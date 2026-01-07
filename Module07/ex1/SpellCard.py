from enum import Enum
from ex0.Card import Card


class Effect(Enum):
    damage = "damage"
    heal = "heal"
    buff = "buff"
    debuff = "debuff"


class SpellCard(Card):
    def __init__(self,  name: str, cost: int, rarity: str, effect_type: str):
        super().__init__(name, cost, rarity)
        self.effect_type = Effect(effect_type)

    def play(self, game_state: dict) -> dict:
        return {
            "card_played": self.name,
            "mana_used": self.cost,
            "effect": f"Deal {self.cost} {self.effect_type.value} to target"
        }

    def resolve_effect(self, targets: list) -> dict:
        return {}
