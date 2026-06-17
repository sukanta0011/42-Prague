from ex0.Card import Card
from ex2.Combatable import Combatable
from ex4.Rankable import Rankable


class TournamentCard(Card, Combatable, Rankable):
    def __init__(self, name: str, cost: int, rarity: str,
                 combat_type: str, damage: str, health: int, shield: int,
                 rating: int, wins: int, losses: int):
        Card.__init__(self, name, cost, rarity)
        Combatable.__init__(self, combat_type, damage, health, shield)
        Rankable.__init__(self, rating, wins, losses)

    def play(self, game_state: dict) -> dict:
        pass

    def attack(self, target) -> dict:
        pass

    def defend(self, incoming_damage: int) -> dict:
        pass

    def get_combat_stats(self) -> dict:
        pass

    def get_tournament_stats(self) -> dict:
        pass

    def calculate_rating(self) -> int:
        pass

    def update_wins(self, wins: int) -> None:
        self.wins += wins
        self.rating += 16

    def update_losses(self, losses: int) -> None:
        self.losses += losses
        self.rating -= 16

    def get_rank_info(self) -> dict:
        pass
