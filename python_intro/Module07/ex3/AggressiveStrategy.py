from .GameStrategy import GameStrategy
from ex0.CreatureCard import CreatureCard
from ex1.ArtifactCard import ArtifactCard
from ex1.SpellCard import SpellCard


class AggressiveStrategy(GameStrategy):
    def execute_turn(self, hand: list, battlefield: list) -> dict:
        targets = self.prioritize_targets(battlefield)
        hand_dict = self.arrange_hands(hand)
        cards_used = []
        mana_used = 0
        if (len(hand_dict["creatures"]) > 0):
            low_cost_creature = self.get_low_cast_creature(
                hand_dict["creatures"])
            cards_used.append(low_cost_creature.name)
            mana_used += low_cost_creature.cost
        if (len(hand_dict["spells"]) > 0):
            cards_used.append(hand_dict["spells"][0].name)
            mana_used += hand_dict["spells"][0].cost
        if (len(hand_dict["artifacts"]) > 0):
            cards_used.append(hand_dict["artifacts"][0].name)
            mana_used += hand_dict["artifacts"][0].cost

        return {
            "cards_played": cards_used,
            "mana_used": mana_used,
            "targets_attacked": targets,
            "damage_dealt": 8
        }

    def get_strategy_name(self) -> str:
        return "AggressiveStrategy"

    def prioritize_targets(self, available_targets: list) -> list:
        priority_list = []
        for target in available_targets:
            if "player" in target.lower():
                priority_list.append(target)
        return priority_list

    def arrange_hands(self, hand: list) -> dict:
        creature_cards = []
        spell_cards = []
        artifact_cards = []
        for card in hand:
            if isinstance(card, CreatureCard):
                creature_cards.append(card)
            elif isinstance(card, SpellCard):
                spell_cards.append(card)
            elif isinstance(card, ArtifactCard):
                artifact_cards.append(card)
        return {
            "creatures": creature_cards,
            "spells": spell_cards,
            "artifacts": artifact_cards
        }

    def get_low_cast_creature(self, creatures:
                              list[CreatureCard]) -> CreatureCard:
        min_mana = 100
        name = creatures[0]
        for creature in creatures:
            if creature.cost < min_mana:
                min_mana = creature.cost
                name = creature
        return name
