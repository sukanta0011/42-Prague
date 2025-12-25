def get_unique_achievement(achievements: list) -> set:
    """Perform OR operation to get unique values from the list of sets"""
    if len(achievements) > 0:
        unique = achievements[0]
    else:
        raise ValueError("Error: Empty list")

    for achievement in achievements:
        try:
            unique = unique.union(achievement)
        except Exception:
            print(f"Error: {achievement} is not a set")
    return unique


def get_common_achievement(achievements: list) -> set:
    """Perform AND operation to get common values from the list of sets"""
    if len(achievements) > 0:
        common = achievements[0]
    else:
        raise ValueError("Error: Empty list")

    for achievement in achievements:
        try:
            common = common.intersection(achievement)
        except Exception:
            print(f"Error: {achievement} is not a set")
    return common


def get_rare_achievement(achievements: list) -> set:
    """Get the set of items only achieved by single players"""
    rare = set()
    for i, achievement in enumerate(achievements):
        set_i = achievement
        for j, achievement in enumerate(achievements):
            if i != j:
                set_i = set_i - achievement
        rare = rare | set_i
    return (rare)


if __name__ == "__main__":
    print("=== Achievement Tracker System ===")
    print()
    alice = {'first_kill', 'level_10', 'treasure_hunter', 'speed_demon'}
    bob = {'first_kill', 'level_10', 'boss_slayer', 'collector'}
    charlie = {'level_10', 'treasure_hunter', 'boss_slayer',
               'speed_demon', 'perfectionist'}
    print(f"Player alice achievements: {alice}")
    print(f"Player bob achievements: {bob}")
    print(f"Player charlie achievements: {charlie}")
    players = [alice, bob, charlie]
    print()
    try:
        print("=== Achievement Analytics ===")
        unique = get_unique_achievement(players)
        print(f"All unique achievements: {unique}")
        print(f"Total unique achievements: {len(unique)}")
        print()
        common = get_common_achievement(players)
        print(f"Common to all players: {common}")
        print(f"Rare achievements (1 player): {get_rare_achievement(players)}")
        print()
        common = get_common_achievement([alice, bob])
        print(f"Alice vs Bob common: {common}")
        print(f"Alice unique: {alice - common}")
        print(f"Bob unique: {bob - common}")
    except ValueError as e:
        print(f"{e}")
