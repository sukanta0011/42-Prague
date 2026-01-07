from ex0.CreatureCard import CreatureCard
from .ArtifactCard import ArtifactCard
from .Deck import Deck
from .SpellCard import SpellCard


dragon = {'name': 'Fire Dragon',
          'cost': 5,
          'rarity': 'Legendary',
          'attack': 7,
          'health': 5
          }
lightning_bolt = {'name': 'Lightning Bolt', 'cost': 3, 'rarity': 'Common', 'effect_type': 'damage'}
mana_crystal = {'name': 'Mana Crystal', 'cost': 2, 'rarity': 'Common', 'durability': 5, 'effect': 'Permanent: +1 mana per turn'}

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
card = deck.draw_card()
print(f"Play result: {card.play({})}")
card = deck.draw_card()
print(f"Play result: {card.play({})}")
card = deck.draw_card()
print(f"Play result: {card.play({})}")

print("\nPolymorphism in action: Same interface, different card behaviors!")
