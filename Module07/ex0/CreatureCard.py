from .Card import Card


class CreatureCard(Card):
    """Special class to manage creature cads"""

    def __init__(self, name: str, cost: int, rarity: str,
                 attack: int, health: int):
        super().__init__(name, cost, rarity)
        self.attack = attack if attack >= 0 else 0
        self.health = health if health >= 0 else 0

    def play(self, game_state: dict) -> dict:
        return {
            "card_played": self.name,
            "mana_used": self.cost,
            "effect": "Creature summoned to battlefield"
        }

    def attack_target(self, target: dict) -> dict:
        attacker_name = self.name
        target_name = target['name']
        damage_dealt = self.attack
        if damage_dealt > target['health']:
            combat_resolved = True
        else:
            combat_resolved = False
        return {
            'attack': attacker_name,
            'target': target_name,
            'damage_dealt': damage_dealt,
            'combat_resolved': combat_resolved
        }
