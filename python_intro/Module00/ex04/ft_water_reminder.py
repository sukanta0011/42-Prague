def ft_water_reminder():
    """Remind the watering of plants based on last watered day"""
    lst_watered = int(input("Days since last watering: "))
    if (lst_watered > 2):
        print("Water the plants!")
    else:
        print("Plants are fine.")
