def ft_harvest_total():
    """Clculate total harvest amount in 3 days"""
    day1_hrvst = int(input("Day 1 harvest: "))
    day2_hrvst = int(input("Day 2 harvest: "))
    day3_hrvst = int(input("Day 3 harvest: "))
    total_hrvst = day1_hrvst + day2_hrvst + day3_hrvst
    print("Total harvest:", total_hrvst)
