import random
from ex0.Card import Card
from ex0.CreatureCard import CreatureCard
from ex1.SpellCard import SpellCard
from ex1.ArtifactCard import ArtifactCard


class Deck:
    def __init__(self) -> None:
        self.all_cards = []

    def add_card(self, card: Card) -> None:
        """Add new card to the Deck"""
        self.all_cards.append(card)

    def remove_card(self, card_name: str) -> bool:
        """Remove card from the deck"""
        for idx, card in enumerate(self.all_cards):
            if card.name == card_name:
                self.all_cards.pop(idx)
                return True
        print(f"{card_name} is not in the deck")
        return False

    def shuffle(self) -> None:
        random.shuffle(self.all_cards)

    def draw_card(self) -> Card:
        """Return a random card from the Deck"""
        try:
            card = self.all_cards[-1]
            self.all_cards.pop(-1)
            return card
        except IndexError:
            print("Deck is empty")

    def get_deck_stats(self) -> dict:
        """Return total_cards, creatures, spells
           artifacts, avg_cost in the deck"""
        total_cards = len(self.all_cards)
        creatures = 0
        spells = 0
        artifacts = 0
        total_cost = 0
        for card in self.all_cards:
            if isinstance(card, CreatureCard):
                creatures += 1
            if isinstance(card, SpellCard):
                spells += 1
            if isinstance(card, ArtifactCard):
                artifacts += 1
            total_cost += card.cost
        return {
            "total_cards": total_cards,
            "creatures": creatures,
            "spells": spells,
            "artifacts": artifacts,
            "avg_cost": round(total_cost / total_cards, 1)
        }
