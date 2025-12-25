import math


class ParsingError(Exception):
    """Custom class to show Parsing error"""
    pass


class CoordinateError(ParsingError):
    """Custom class to show coordinate related"""
    pass


def get_distance(coord1: tuple, coord2: tuple) -> float:
    """Measure the distance two points in 3D"""
    x1, y1, z1 = coord1
    x2, y2, z2 = coord2

    dist = math.sqrt((x1 - x2)**2 + (y1 - y2)**2 + (z1 - z2)**2)
    return dist


def parse_coordinate(co_str: str) -> tuple:
    """Parse the 3D coordinate from the string"""
    coordinate = co_str.split(",")
    if len(coordinate) == 3:
        x = int(coordinate[0])
        y = int(coordinate[1])
        z = int(coordinate[2])
    else:
        raise CoordinateError("Number of co-ordinates are not 3")
    return ((x, y, z))


def main():
    """Main program to parse and calculate the distance between
       two points in 3D"""
    pos = (10, 20, 5)
    print(f"Position created: {pos}")
    zero_coords = (0, 0, 0)
    dist = get_distance(pos, zero_coords)
    print(f"Distance between {zero_coords} and {pos}: {dist:.2f}")
    print()

    coord_str = "3,4,0"
    print(f"Parsing coordinates: \"{coord_str}\"")
    parsed_pos = parse_coordinate(coord_str)
    print(f"Parsed position: {parsed_pos}")
    dist = get_distance(parsed_pos, zero_coords)
    print(f"Distance between {zero_coords} and {pos}: {dist:.2f}")
    print()

    coord_str = "abc,def,ghi"
    print(f"Parsing invalid coordinates: \"{coord_str}\"")
    try:
        parsed_pos = parse_coordinate(coord_str)
        print(f"Parsed position: {parsed_pos}")

    except ValueError as e:
        print(f"Error parsing coordinates: {e}")
        print(f"Error details - Type: {type(e).__name__}, Args: {e.args}")
    print()
    print("Unpacking demonstration:")
    x, y, z = parsed_pos
    print(f"Player at x={x}, y={y}, z={z}")
    print(f"Coordinates: X={x}, Y={y}, Z={z}")


if __name__ == "__main__":
    print("=== Game Coordinate System ===")
    print()
    main()
