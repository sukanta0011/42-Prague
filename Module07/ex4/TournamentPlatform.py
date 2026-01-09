from ex4.TournamentCard import TournamentCard


class TournamentPlatform:
    def __init__(self):
        self.registered_cards = []
        self.category = {}

    def register_card(self, card: TournamentCard) -> str:

        self.registered_cards.append({
            "name": card.name,
            "id": name,
            "rating": card.rating,
            "wins": card.wins,
            "losses": card.losses
        })


    def create_match(self, card1_id: str, card2_id: str) -> dict:
        pass

    def get_leaderboard(self) -> list:
        pass

    def generate_tournament_report(self) -> dict:
        pass
