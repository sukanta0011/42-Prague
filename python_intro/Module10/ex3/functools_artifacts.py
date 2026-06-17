from functools import reduce, partial, lru_cache, singledispatch
import operator


def base_enhancer(power: int, element: str, target: str):
    return f"{element} spell hits the {target}. {target} HP reduced by {power}"


def spell_reducer(spells: list[int], operation: str) -> int:
    if operation == 'add':
        return reduce(operator.add, spells)
    elif operation == 'multiply':
        return reduce(operator.mul, spells)
    elif operation == 'max':
        return reduce(max, spells)
    elif operation == 'min':
        return reduce(min, spells)
    else:
        print(f"Error: '{operation}' not valid")
        print("Use 'add', 'multiply', 'min', 'max'")
        return 0


def partial_enchanter(base_enchantment: callable) -> dict[str, callable]:
    fire_enchant = partial(base_enchantment, power=50, element="Fire")
    ice_enchant = partial(base_enchantment, power=50, element="Ice")
    lightning_enchant = partial(base_enchantment, power=50,
                                element="Lightning")
    return {"fire_enchant": fire_enchant,
            "ice_enchant": ice_enchant,
            "lightning_enchant": lightning_enchant}


@lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    if n == 0:
        return 0
    if n == 1:
        return 1
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> callable:
    @singledispatch
    def cast(input):
        return f"{input} spell is enhanced"

    @cast.register(int)
    def _(input):
        return f"{input} pint damage"

    @cast.register(list)
    def _(input):
        spells = []
        for spell in input:
            spells.append(f"{spell} is casted")
        return spells

    return cast


if __name__ == "__main__":
    spell_powers = [13, 13, 27, 44, 44, 17]
    operations = ['add', 'multiply', 'max', 'min']
    fibonacci_tests = [8, 12, 14]
    print("Testing spell reducer...")
    print(f"Sum: {spell_reducer(spell_powers, 'add')}")
    print(f"Product: {spell_reducer(spell_powers, 'multiply')}")
    print(f"Max: {spell_reducer(spell_powers, 'max')}")
    print(f"Min: {spell_reducer(spell_powers, 'min')}")
    print()
    print("Testing partial enchanter...")
    attack = partial_enchanter(base_enhancer)
    print(f"{attack['fire_enchant'](target='Dragon')}")
    print(f"{attack['ice_enchant'](target='Dragon')}")
    print(f"{attack['lightning_enchant'](target='Dragon')}")
    print()
    print("Testing memoized fibonacci...")
    print(f"Fib(10): {memoized_fibonacci(10)}")
    print(f"Fib(15): {memoized_fibonacci(15)}")
    print()
    print("Testing spell caster...")
    cast = spell_dispatcher()
    print(f"str: {cast('Fire')}")
    print(f"int: {cast(10)}")
    print(f"list: {cast(['Fire', 'Water'])}")
