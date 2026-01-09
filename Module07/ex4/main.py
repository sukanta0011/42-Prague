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
          'loss': 0
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
          'loss': 0
          }

def main():
    print("=== DataDeck Tournament Platform ===\n")
    print("Registering Tournament Cards...")
    card1 = TournamentCard(**dragon)
    card2 = TournamentCard(**wizard)
    




if __name__ == "__main__":
    main()