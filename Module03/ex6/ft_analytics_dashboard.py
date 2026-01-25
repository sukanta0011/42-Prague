if __name__ == "__main__":
    print("=== Game Analytics Dashboard ===\n")
    players = ["alice", "bob", "charlie", "diana", "eve"]
    scores = [1000, 4500, 500, 2500, 2000]
    activity = ["online", "offline", "online", "online", "offline"]
    locations = ["north", "east", "central", "east", "south"]
    score_cat = ["high", "medium", "low"]
    achievements = {
        "alice": ['first_kill', 'level_10', 'treasure_hunter', 'speed_demon'],
        "bob": ['first_kill', 'level_10', 'boss_slayer', 'collector'],
        "charlie": ['level_10', 'treasure_hunter', 'boss_slayer',
                    'speed_demon', 'perfectionist'],
        "diana": ['pixel_perfect', 'treasure_seeker', 'combo_king'],
        "eve": ['level_master', 'speed_runner', 'boss_hunter']
    }

    print("=== List Comprehension Examples ===")
    high_score = [players[idx] for idx, score
                  in enumerate(scores) if score > 2000]
    active = [players[idx] for idx, status
              in enumerate(activity) if status == "online"]
    print(f"High scorers (>2000): {high_score}")
    print(f"Scores doubled: {[s * 2 for s in scores]}")
    print(f"Active players: {active}")
    print()

    print("=== Dict Comprehension Examples ===")
    players_dict = {k: v for (k, v) in zip(players, scores)}
    score_dict = {cat: sum(1 for s in scores if (
                 (cat == "high" and s > 2000) or
                 (cat == "medium" and 1000 <= s <= 2000) or
                 (cat == "low" and s < 1000)))
                 for cat in score_cat}
    achievement_counts = {k: len(v) for (k, v) in achievements.items()}
    print(f"Player scores: {players_dict}")
    print(f"Score categories: {score_dict}")
    print(f"Achievement counts: {achievement_counts}")
    print()

    print("=== Set Comprehension Examples ===")
    unique_players = {p for p in players}
    unique_achievements = {achievement for p in achievements
                           for achievement in achievements[p]}
    active_region = {loc for loc in locations}
    print(f"Unique players: {unique_players}")
    print(f"Unique achievements: {unique_achievements}")
    print(f"Active regions:: {active_region}")

    print("\n=== Combined Analysis ===")
    print(f"Total players: {len(unique_players)}")
    print(f"Total unique achievements: {len(unique_achievements)}")
    print(f"Average score: {sum(scores) / len(scores):.1f}")
    top_player = players[scores.index(max(scores))]
    print(f"Top performer: {top_player} " +
          f"({max(scores)}, {achievement_counts[top_player]})")
