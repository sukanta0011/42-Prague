def ft_print_recursive(day: int):
    """Function to print output"""
    if (day > 1):
        ft_print_recursive(day - 1)
    print("Day", day)


def ft_count_harvest_recursive():
    """Counts the days still harvest in recursive way"""
    until_hrvst = int(input("Days until harvest: "))
    ft_print_recursive(until_hrvst)
    print("Harvest time!")
