def fireball(target: str) -> str:
    return f"Fireball hits {target}"


def water(target: str) -> str:
    return f"Water hits {target}"


def heal(target: str) -> str:
    return f"Heals {target}"


def thunder(power: int) -> int:
    return power


def spell_to_apply(target: str, spell: str):
    return f"{spell} hits the {target}"


def check_compatibility(target: str, spell: str):
    if spell in target:
        return False
    return True


def spell_combiner(spell1: callable, spell2: callable) -> callable:
    def combined_spell(target: str):
        result1 = spell1(target)
        result2 = spell2(target)
        return (result1, result2)
    return combined_spell


def power_amplifier(base_spell: callable, multiplier: int) -> callable:
    def amplified_spell(power: int):
        return base_spell(power) * multiplier
    return amplified_spell


def conditional_caster(condition: callable, spell: callable) -> callable:
    def spell_caster(target: str, spell_used: str):
        if condition(target, spell_used):
            return spell(target, spell_used)
        return "Spell fizzled"
    return spell_caster


def spell_sequence(spells: list[callable]) -> callable:
    def apply_all_spell(target: str):
        results = []
        for spell in spells:
            results.append(spell(target))
        return results
    return apply_all_spell


if __name__ == "__main__":
    test_values = [23, 9, 12]
    test_targets = ['Dragon', 'Goblin', 'Wizard', 'Knight']
    combined = spell_combiner(fireball, heal)
    mega_fireball = power_amplifier(thunder, 3)
    apply_spell = conditional_caster(check_compatibility, spell_to_apply)
    apply_spell_in_sequence = spell_sequence([fireball, water, heal])

    print(combined("Dragon"))
    print(mega_fireball(10))
    print(apply_spell("Thunder Dragon", "Water"))
    print(apply_spell("Thunder Dragon", "Thunder"))
    print(apply_spell_in_sequence("Dragon"))
