from .CardFactory import CardFactory
from .GameStrategy import GameStrategy


class GameEngine:
    def __init__(self) -> None:
        self.turns_simulated = 0

    def configure_engine(self, factory: CardFactory,
                         strategy: GameStrategy) -> None:
        self.factory = factory
        self.strategy = strategy

    def simulate_turn(self) -> dict:
        try:
            self.turns_simulated += 1
            dragon = self.factory.create_creature("Dragon")
            goblin = self.factory.create_creature("Goblin")
            lightning = self.factory.create_spell("Lightning")
            self.hand = [dragon, goblin, lightning]
            self.battlefield = ["Enemy Player", "Enemy Goblin"]
            self.result = self.strategy.execute_turn(self.hand,
                                                     self.battlefield)
            return {
                "turns_simulated": self.turns_simulated,
                "strategy_used": self.strategy.get_strategy_name(),
                "total_damage": self.result["damage_dealt"],
                "cards_created": len(self.hand)
            }
        except Exception as e:
            print(f"Error: {e}")
            return {}

    def get_engine_status(self) -> dict:
        return {}
