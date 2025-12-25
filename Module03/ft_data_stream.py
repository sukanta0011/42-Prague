import random
import sys
import time


def generate_data_stream(counts: int):
    players = ["alice", "bob", "charlie", "frank", "diana"]
    events = ["killed monster", "found treasure", "leveled up", "login"]
    levels = [i for i in range(1, 15)]
    for i in range(1, counts + 1):
        player = random.choice(players)
        event = random.choice(events)
        level = random.choice(levels)
        yield (i, player, level, event)


def event_analyzer(counts: int):
    start_time = time.time()
    events = generate_data_stream(counts)
    total_events = 0
    high_level_player = 0
    treasure_event = 0
    level_up_event = 0

    for _, _, level, event in events:
        total_events += 1
        if level > 10:
            high_level_player += 1
        if "treasure" in event:
            treasure_event += 1
        if "leveled up" in event:
            level_up_event += 1
    print(f"Total events processed: {total_events}")
    print(f"High-level players (10+): {high_level_player}")
    print(f"Treasure events: {treasure_event}")
    print(f"Level-up events: {level_up_event}")
    print()
    end_time = time.time()
    duration = end_time - start_time
    print(f"Processing time: {duration:.3f} seconds")


def test_gen_vs_lst(counts: int):
    gen = (i for i in range(counts))
    lst = [i for i in range(counts)]
    print(f"Generator size ({counts}): {sys.getsizeof(gen)} bytes")
    print(f"List size ({counts}): {sys.getsizeof(lst)} bytes")


def fib_generator(num: int):
    """Generate fibonacci series"""
    a = 0
    b = 1
    for _ in range(num):
        yield a
        a, b = b, a + b


def is_prime(start: int) -> bool:
    for i in range(2, (start + 2) // 2):
        if start % i == 0:
            return False
    return True


def prime_num_generator(num: int):
    """Generate prime numbers"""
    i = 1
    for _ in range(num):
        while True:
            i += 1
            if is_prime(i):
                yield (i)
                break


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")
    print()
    print("Processing 1000 game events...")
    print()
    events = generate_data_stream(1000)
    for i, player, level, event in events:
        print(f"Event {i}: Player {player} (level {level}) {event}")
        if i == 3:
            break
    print("...")
    print()
    print("=== Stream Analytics ===")
    event_analyzer(100000)
    print()
    fib_num = 10
    gen = fib_generator(fib_num)
    print(f"Fibonacci sequence (first {fib_num}): " +
          f"{', '.join(str(num) for num in gen)}")
    prime_num = 5
    gen = prime_num_generator(prime_num)
    print(f"Prime numbers (first {prime_num}): " +
          f"{', '.join(str(num) for num in gen)}")
