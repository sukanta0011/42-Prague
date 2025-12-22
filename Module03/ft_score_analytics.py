import sys

print("=== Player Score Analytics ===")
scores = []
if (len(sys.argv) > 1):
    for args in sys.argv[1:]:
        try:
            scores.append(int(args))
        except ValueError:
            print(f"Caught ValueError: {args} not a number")

    print(f"Scores processed: {scores}")
    print(f"Total players: {len(scores)}")
    print(f"Total score: {sum(scores)}")
    print(f"Average score: {sum(scores)/len(scores)}")
    print(f"High score: {max(scores)}")
    print(f"Low score: {min(scores)}")
    print(f"Score range: {max(scores) - min(scores)}")
else:
    print("No scores provided. Usage: python3" +
          f" {sys.argv[0]} <score1> <score2> ...")
