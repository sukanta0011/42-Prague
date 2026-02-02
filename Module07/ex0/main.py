from ex0.CreatureCard import CreatureCard


def main():
    print("=== DataDeck Card Foundation ===")
    print()
    print("Testing Abstract Base Class Design:")
    print()
    print("CreatureCard Info:")

    dragon = {'name': 'Fire Dragon',
              'cost': 5,
              'rarity': 'Legendary',
              'attack': 7,
              'health': 5
              }

    goblin = {'name': 'Goblin Warrior',
              'cost': 1,
              'rarity': 'Common',
              'attack': 1,
              'health': 1
              }
    print(dragon)
    fire_dragon = CreatureCard(dragon['name'], dragon['cost'],
                               dragon['rarity'], dragon['attack'],
                               dragon['health'])

    print()
    print("Playing Fire Dragon with 6 mana available:")
    print(f"Playable: {fire_dragon.is_playable(6)}")

    game_state = {
        'card_played': 'Fire Dragon',
        'mana_used': 5,
    }
    print(f"Play result: {fire_dragon.play(game_state)}")
    print()
    print("Fire Dragon attacks Goblin Warrior:")
    print(f"Attack result: {fire_dragon.attack_target(goblin)}")
    print()
    print("Testing insufficient mana (3 available):")
    print(f"Playable: {fire_dragon.is_playable(3)}")
    print()
    print("Abstract pattern successfully demonstrated!")


if __name__ == "__main__":
    try:
        main()
    except Exception as e:
        print(e)
