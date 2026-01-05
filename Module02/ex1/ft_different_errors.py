def garden_operations(height=None, days=None, log_path=None,
                      plants_info=None):
    """Testing garden operation function to handle multiple error scenarios"""
    try:
        height_int = 0
        avg_growth = 0
        logs = ""
        oak_height = 0
        if height is not None:
            height_int = int(height)
        if days is not None:
            avg_growth = height_int / int(days)
        if log_path is not None:
            logs = open(log_path)
        if plants_info is not None:
            oak_height = plants_info["Oak"]
        return (height, avg_growth, logs, oak_height)

    except ValueError:
        print("Caught ValueError: invalid literal for int()")
    except ZeroDivisionError:
        print("Caught ZeroDivisionError: division by zero")
    except FileNotFoundError:
        print(f"Caught FileNotFoundError: No such file path '{log_path}'")
    except KeyError:
        print("Caught KeyError: 'plants_info\\_Oak'")
    except Exception as e:
        print(f"Caught Unknown error: {e}")
    return None


def test_error_types():
    """Testing the error handling of garden operation"""
    plants_info = {"Rose": 10}
    fake_path = "missing.txt"

    print("Testing ValueError...")
    garden_operations(height="abc")
    print()

    print("Testing ZeroDivisionError...")
    garden_operations(height="10", days=0)
    print()

    print("Testing FileNotFoundError...")
    garden_operations(log_path=fake_path)
    print()

    print("Testing KeyError...")
    garden_operations(plants_info=plants_info)
    print()

    print("Testing multiple errors together...")
    val = 0
    try:
        val = int("abc")
    except (ValueError, FileNotFoundError, ZeroDivisionError, KeyError):
        pass
    print("Caught an error, but program continues")
    print()
    return val


if __name__ == "__main__":
    print("=== Garden Error Types Demo ===")
    test_error_types()
    print("All error types tested successfully!")
