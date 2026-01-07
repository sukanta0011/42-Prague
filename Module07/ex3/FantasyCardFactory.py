from .CardFactory import CardFactory
from ex0.Card import Card
from ex0.CreatureCard import CreatureCard
from ex1.ArtifactCard import ArtifactCard
from ex1.SpellCard import SpellCard


class FantasyCardFactory(CardFactory):
    def create_creature(self, name_or_power) -> Card:
        if isinstance(name_or_power, str):
            if "Dragon" in name_or_power:
                return CreatureCard(name_or_power, 5, "Legendary", 7, 5)
            else:
                return CreatureCard(name_or_power, 1, "Common", 1, 1)
        elif isinstance(name_or_power, int):
            return CreatureCard("Dragon", 5, "Legendry", name_or_power, 5)
        else:
            print("Please add a proper name or power, else get a Goblin")
            return CreatureCard("Goblin", 1, "Common", 1, 1)

    def create_spell(self, name_or_power) -> Card:
        if isinstance(name_or_power, str):
            return SpellCard(name_or_power, 4, "Uncommon", "damage")
        elif isinstance(name_or_power, int):
            return SpellCard("Fireball", 5, "Legendry", "damage")
        else:
            print("Please add a proper name or power, else get a Ice Shard")
            return SpellCard("Ice Shard", 2, "Common", "damage")

    def create_artifact(self, name_or_power) -> Card:
        if isinstance(name_or_power, str):
            return ArtifactCard(name_or_power, 2, "Common", 5,
                                "Permanent: +1 mana per turn")
        else:
            print("Please add a proper name, else get a Ice Shard")
            return ArtifactCard("Mana Crystal", 2, "Common", 5,
                                "Permanent: +1 mana per turn")

    def create_themed_deck(self, size: int) -> dict:
        pass

    def get_supported_types(self) -> dict:
        pass
