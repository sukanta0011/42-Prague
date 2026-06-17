from abc import ABC, abstractmethod


class Magical(ABC):
    def __init__(self, mana_channel: int) -> None:
        self.mana_channel = mana_channel

    @abstractmethod
    def cast_spell(self, spell_name: str, target: list) -> dict:
        pass

    @abstractmethod
    def channel_mana(self, amount: int) -> dict:
        pass

    @abstractmethod
    def get_magic_states(self) -> dict:
        pass
