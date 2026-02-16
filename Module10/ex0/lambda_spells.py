def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    sorted_list = sorted(
        artifacts,
        key=lambda artifact: artifact['power'],
        reverse=True
        )
    return (sorted_list)


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    filtered_mages = filter(
        lambda mage: mage['power'] >= min_power,
        mages
    )
    return list(filtered_mages)


def spell_transformer(spells: list[str]) -> list[str]:
    transformed_spell = map(
        lambda spell: f"* {spell} *",
        spells
    )
    return list(transformed_spell)


def mage_stats(mages: list[dict]) -> dict:
    powers = [m['power'] for m in mages]
    return {
        'max_power': max(powers),
        'min_power': min(powers),
        'avg_power': round(sum(powers) / len(powers), 2)
    }


if __name__ == "__main__":
    artifacts = [{'name': 'Fire Staff', 'power': 107, 'type': 'armor'},
                 {'name': 'Crystal Orb', 'power': 84, 'type': 'relic'},
                 {'name': 'Wind Cloak', 'power': 75, 'type': 'relic'},
                 {'name': 'Shadow Blade', 'power': 116, 'type': 'focus'}]
    mages = [{'name': 'Riley', 'power': 65, 'element': 'water'},
             {'name': 'Jordan', 'power': 57, 'element': 'light'},
             {'name': 'Casey', 'power': 66, 'element': 'ice'},
             {'name': 'Zara', 'power': 99, 'element': 'shadow'},
             {'name': 'Sage', 'power': 95, 'element': 'light'}]
    spells = ['fireball', 'freeze', 'earthquake', 'lightning']
    print(artifact_sorter(artifacts))
    print(power_filter(mages, 70))
    print(spell_transformer(spells))
    print(mage_stats(mages))
