from .CardFactory import CardFactory
from .FantasyCardFactory import FantasyCardFactory
from .AggressiveStrategy import AggressiveStrategy
from .GameEngine import GameEngine
from ex0.Card import Card
from ex0.CreatureCard import CreatureCard
from ex1.ArtifactCard import ArtifactCard
from ex1.SpellCard import SpellCard


def main():
    print("Configuring Fantasy Card Game...")
    factory = FantasyCardFactory()
    print(f"Factory: {type(factory).__name__}")
    strategy = AggressiveStrategy()
    print(f"Strategy: {strategy.get_strategy_name()}")
    print(f"Available types: {factory.get_supported_types()}")
    dragon = factory.create_creature("Dragon")
    goblin = factory.create_creature("Goblin")
    lightning = factory.create_spell("Lightning")
    hand = [dragon, goblin, lightning]
    print("Simulating aggressive turn...")
    print(f"Hand: {", ".join([f"{card.name} ({(card.cost)})"
                             for card in hand])}")

    print("\nTurn execution:")
    print(f"Strategy: {strategy.get_strategy_name()}")
    print("Actions: "
          f"{strategy.execute_turn(hand, ["Enemy Player", "Enemy Goblin"])}")

    game_engine = GameEngine()
    game_engine.configure_engine(factory, strategy)


if __name__ == "__main__":
    print("=== DataDeck Game Engine ===\n")
    main()
