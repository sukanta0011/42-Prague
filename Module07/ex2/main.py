from ex0.Card import Card
from .Combatable import Combatable
from .Magical import Magical
from .EliteCard import EliteCard


arcane_wizard = {'name': 'Arcane Warrior',
                 'cost': 4,
                 'rarity': 'Elite',
                 'combat_type': 'melee',
                 'damage': 5,
                 'health': 15,
                 'shield': 3,
                 'mana_channel': 3,
                 }

print("=== DataDeck Ability System ===\n")
print("EliteCard capabilities:")
print(f"- Card: {[method for method in vars(Card)
                 if not method.startswith("_")]}")
print(f"- Combatable: {[method for method in vars(Combatable)
                       if not method.startswith("_")]}")
print(f"- Magical: {[method for method in vars(Magical)
                    if not method.startswith("_")]}")

elite_card = EliteCard(**arcane_wizard)
print("\nPlaying Arcane Warrior (Elite Card):")
print("\nCombat phase:")
print(f"Attack result: {elite_card.attack("Enemy")}")
print(f"Defense result: {elite_card.defend(5)}")

print("\nMagic phase:")
print(f"Spell cast: {elite_card.cast_spell("Fireball",
                                           ['Enemy1', 'Enemy2'])}")
print(f"Mana channel: {elite_card.channel_mana(10)}")

print("\nMultiple interface implementation successful!")
