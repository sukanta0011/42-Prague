def ft_count_harvest_iterative():
    """Counts the days still harvest in iterative way"""
    until_hrvst = int(input("Days until harvest: "))
    for i in range(1, until_hrvst + 1):
        print("Day", i)
    print("Harvest time!")
