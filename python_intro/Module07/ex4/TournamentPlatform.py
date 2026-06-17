from ex4.TournamentCard import TournamentCard


class TournamentPlatform:
    def __init__(self):
        self.registered_cards = []
        self.category = {}
        self.match_counter = 0
        self.platform_status = "active"

    def register_card(self, card: TournamentCard) -> str:
        id = self.generate_card_id(card.name)
        self.registered_cards.append({
            "id": id,
            "card": card
        })
        return f"{card.name} (ID: {id})"

    def create_match(self, card1_id: str, card2_id: str) -> dict:
        card1 = self.get_card_by_id(card1_id)
        card2 = self.get_card_by_id(card2_id)
        if card1 is not None and card2 is not None:
            self.match_counter += 1
            if card1.damage > card2.damage:
                winner = card1
                loser = card2
                winner_id = card1_id
                loser_id = card2_id
            elif card1.damage < card2.damage:
                winner = card2
                loser = card1
                winner_id = card2_id
                loser_id = card1_id
            else:
                return {"Status": "Draw"}

            winner.update_wins(1)
            loser.update_losses(1)
        else:
            return {"Error": "Provided cards ids are not valid,"
                    "register the card first"}
        return {
            "winner": winner_id,
            "loser": loser_id,
            "winner_rating": winner.rating,
            "loser_rating": loser.rating
        }

    def get_leaderboard(self) -> list:
        sorted_card = sorted(self.registered_cards,
                             key=lambda x: x["card"].rating, reverse=True)
        return sorted_card

    def generate_tournament_report(self) -> dict:
        avg_rating = sum([card["card"].rating for card in
                          self.registered_cards]) / len(self.registered_cards)
        return {
            "total_cards": len(self.registered_cards),
            "matches_played": self.match_counter,
            "avg_rating": avg_rating,
            "platform_status": self.platform_status
        }

    def generate_card_id(self, name: str) -> str:
        category_name = name.split(" ")[-1].lower()
        if category_name in self.category.keys():
            self.category[category_name] += 1
        else:
            self.category[category_name] = 1
        return f"{category_name}_{self.category[category_name]:03d}"

    def get_card_by_id(self, id: str) -> TournamentCard | None:
        for card in self.registered_cards:
            if (id == card['id']):
                return card['card']
        print(f"There is no registered card by id {id}")
        return None
