from ex4.TournamentPlatform import TournamentPlatform
from ex4.TournamentCard import TournamentCard


dragon = {'name': 'Fire Dragon',
          'cost': 5,
          'rarity': 'Elite',
          'combat_type': 'Long range',
          'damage': 5,
          'health': 15,
          'shield': 3,
          'rating': 1200,
          'wins': 0,
          'losses': 0
          }

wizard = {'name': 'Ice Wizard',
          'cost': 4,
          'rarity': 'Elite',
          'combat_type': 'Long range',
          'damage': 3,
          'health': 5,
          'shield': 3,
          'rating': 1150,
          'wins': 0,
          'losses': 0
          }


def main():
    print("=== DataDeck Tournament Platform ===\n")
    print("Registering Tournament Cards...")
    card1 = TournamentCard(**dragon)
    card2 = TournamentCard(**wizard)
    tournament = TournamentPlatform()
    print()
    print(tournament.register_card(card1))
    print("- Interfaces: [Card, Combatable, Rankable]")
    print(f"- Rating: {card1.rating}")
    print(f"- Record: {card1.wins}-{card1.losses}")
    print()
    print(tournament.register_card(card2))
    print("- Interfaces: [Card, Combatable, Rankable]")
    print(f"- Rating: {card2.rating}")
    print(f"- Record: {card2.wins}-{card2.losses}")
    print()
    print("Creating tournament match...")
    result = tournament.create_match("dragon_001", "wizard_001")
    print(f"Match result: {result}")
    print()
    print("Tournament Leaderboard:")
    sorted_card = tournament.get_leaderboard()
    for idx, card in enumerate(sorted_card):
        print(f"{idx + 1}. {card['card'].name} - Rating: "
              f"{card['card'].rating}({card['card'].wins}"
              f"-{card['card'].losses})")

    print()
    print("Platform Report:")
    print(tournament.generate_tournament_report())

    print("\n=== Tournament Platform Successfully Deployed! ===")
    print("All abstract patterns working together harmoniously!")


if __name__ == "__main__":
    main()
