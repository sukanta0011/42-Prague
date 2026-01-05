from Card import Card


class CreatureCard(Card):
    """Special class to manage creature cads"""

    def __init__(self, name: str, cost: int, rarity: str,
                 attack: int, health: int):
        super().__init__(name, cost, rarity)
        self.attack = attack
        self.health = health

    def play(self, game_state: dict) -> dict:
        game_state['effect'] = 'Creature summoned to battlefield'
        return game_state

    def attack_target(self, target: dict) -> dict:
        attacker_name = self.name
        target_name = target['name']
        damage_delt = self.attack
        if damage_delt > target['health']:
            combat_resolved = True
        else:
            combat_resolved = False
        return {
            'attack': attacker_name,
            'target': target_name,
            'damage_delt': damage_delt,
            'combat_resolved': combat_resolved
        }
