import alchemy


def test_direct_module_access():
    """Testing direct module access"""
    print("Testing direct module access:")
    print(f"alchemy.elements.create_fire(): {alchemy.elements.create_fire()}")
    print(f"alchemy.elements.create_water(): "
          f"{alchemy.elements.create_water()}")
    print(f"alchemy.elements.create_earth(): "
          f"{alchemy.elements.create_earth()}")
    print(f"alchemy.elements.create_air(): {alchemy.elements.create_air()}")


def test_package_level_access():
    """Testing package-level access (controlled by __init__.py)"""
    print(f"alchemy.create_fire(): {alchemy.create_fire()}")
    print(f"alchemy.create_water(): {alchemy.create_water()}")
    try:
        print(f"alchemy.create_earth(): {alchemy.create_earth()}")
    except AttributeError:
        print("alchemy.create_earth(): AttributeError - not exposed")
    try:
        print(f"alchemy.create_air(): {alchemy.create_air()}")
    except AttributeError:
        print("alchemy.create_air(): AttributeError - not exposed")


if __name__ == "__main__":
    print("=== Sacred Scroll Mastery ===")
    print()
    test_direct_module_access()
    print()
    test_package_level_access()
    print()
    print("Package metadata:")
    print(f"Version: {alchemy.__version__}")
    print(f"Version: {alchemy.__author__}")
