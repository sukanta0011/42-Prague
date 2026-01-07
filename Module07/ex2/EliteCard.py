from ex0.Card import Card
from .Combatable import Combatable
from .Magical import Magical


class EliteCard(Card, Combatable, Magical):
    def __init__(self, name: str, cost: int, rarity: str,
                 combat_type: str, damage: str, health: int,
                 shield: int, mana_channel: int):
        Card.__init__(self, name, cost, rarity)
        Combatable.__init__(self, combat_type, damage,
                            health, shield)
        Magical.__init__(self, mana_channel)

    def play(self, game_state: dict) -> dict:
        return {}

    def cast_spell(self, spell_name: str, target: list) -> dict:
        return {
            "caster": self.name,
            "spell": spell_name,
            "targets": target,
            "mana_used": self.cost
        }

    def channel_mana(self, amount: int) -> dict:
        return {
            "channeled": self.mana_channel,
            "total_mana": amount
        }

    def get_magic_states(self) -> dict:
        return {}

    def attack(self, target: str) -> dict:
        return {
            "attacker": self.name,
            "target": target,
            "damage": self.damage,
            "combat_type": self.combat_type
        }

    def defend(self, incoming_damage: int) -> dict:
        if incoming_damage > self.shield:
            damage_taken = incoming_damage - self.shield
            damage_blocked = self.shield
        else:
            damage_taken = 0
            damage_blocked = incoming_damage
        if damage_taken > self.health:
            is_alive = False
        else:
            is_alive = True

        return {
            "defender": self.name,
            "damage_taken": damage_taken,
            "damage_blocked": damage_blocked,
            "still_alive": is_alive
        }

    def get_combat_stats(self) -> dict:
        return {}
