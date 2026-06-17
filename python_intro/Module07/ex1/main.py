from ex0.CreatureCard import CreatureCard
from ex1.ArtifactCard import ArtifactCard
from ex1.Deck import Deck
from ex1.SpellCard import SpellCard


def main():
    dragon = {'name': 'Fire Dragon',
              'cost': 5,
              'rarity': 'Legendary',
              'attack': 7,
              'health': 5
              }
    lightning_bolt = {'name': 'Lightning Bolt', 'cost': 3,
                      'rarity': 'Common', 'effect_type': 'damage'}
    mana_crystal = {'name': 'Mana Crystal', 'cost': 2,
                    'rarity': 'Common', 'durability': 5,
                    'effect': 'Permanent: +1 mana per turn'}
    print("=== DataDeck Deck Builder ==\n")
    print("Building deck with different card types...")
    deck = Deck()
    fire_dragon = CreatureCard(**dragon)
    lightning_bolt = SpellCard(**lightning_bolt)
    mana_crystal = ArtifactCard(**mana_crystal)
    deck.add_card(fire_dragon)
    deck.add_card(lightning_bolt)
    deck.add_card(mana_crystal)
    print(f"Play result: {deck.get_deck_stats()}")

    print("\nDrawing and playing cards:")
    for _ in range(3):
        print()
        card = deck.draw_card()
        print(f"Drew: {card.get_card_info().get('Name')} "
              f"({card.__class__.__name__})")
        print(f"Play result: {card.play({})}")

    print("\nPolymorphism in action: Same interface, "
          "different card behaviors!")


if __name__ == "__main__":
    main()
