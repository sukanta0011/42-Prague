from functools import wraps
from time import time


def spell_timer(func: callable) -> callable:
    @wraps(func)
    def measured_time(*args, **kwargs):
        start_time = time()
        result = func(*args, **kwargs)
        end_time = time()
        print(f"Spell completed in {(end_time - start_time):.3f} seconds")
        return result
    return measured_time


def power_validator(min_power: int) -> callable:
    def decorator(func: callable) -> callable:
        @wraps(func)
        def wrapper(*args, **kwargs):
            power = args[2] if len(args) > 2 else kwargs.get('power', 0)
            if power > min_power:
                return func(*args, **kwargs)
            return "Insufficient power for this spell"
        return wrapper
    return decorator


def retry_spell(max_attempts: int) -> callable:
    def decorator(func: callable) -> callable:
        @wraps(func)
        def wrapper(*args, **kwargs):
            for attempt in range(1, max_attempts + 1):
                try:
                    result = func(*args, **kwargs)
                    return result
                except Exception:
                    print(f"Spell failed, retrying... (attempt {attempt}" +
                          f"/{max_attempts})")
            return f"Spell casting failed after {max_attempts} "\
                "attempts"
        return wrapper
    return decorator


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        if len(name) > 3:
            for c in name:
                if not c.isalpha() or c.isspace():
                    return False
            return True
        return False

    @power_validator(10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return f"Successfully cast {spell_name} with {power} power"


@spell_timer
def fireball() -> str:
    return "Fireball cast!"


@power_validator(10)
def apply_spell(power: int) -> str:
    return f"Target lost {power} point HP"


@retry_spell(3)
def spell_summery(name: str, power: int, attempt: int = 1) -> str:
    return f"Name: {name}, Power: {int(power)}"


if __name__ == "__main__":
    test_powers = [6, 18, 8, 11]
    spell_names = ['earthquake', 'freeze', 'meteor', 'blizzard']
    mage_names = ['Phoenix', 'Ember', 'Alex', 'Kai', 'Rowan', 'River']
    invalid_names = ['Jo', 'A', 'Alex123', 'Test@Name']
    print("\nTesting spell timer...")
    print(f"Casting {fireball.__name__}...")
    print(f"Result: {fireball()}")
    print("\nTesting power validator...")
    for power in test_powers:
        print(apply_spell(power))
    print("\nTesting retry spell...")
    print(spell_summery('fireball', 50))
    print(spell_summery('earth', '10'))
    print(spell_summery('earth', 'ss'))
    print(spell_summery('Water', 'ss'))
    print("\nTesting MageGuild...")
    mage_guid = MageGuild()
    print(mage_guid.validate_mage_name('Jo'))
    print(mage_guid.validate_mage_name('Jo23'))
    print(mage_guid.validate_mage_name('Alex'))
    for name, power in zip(spell_names, test_powers):
        print(mage_guid.cast_spell(name, power))
