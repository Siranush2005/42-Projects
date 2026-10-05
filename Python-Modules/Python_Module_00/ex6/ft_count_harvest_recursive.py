def helper(d, days):
    if d > days:
        print("Harvest time!")
        return
    print(f"Day {d}")
    helper(d + 1, days)


def ft_count_harvest_recursive():
    days = int(input("Days until harvest: "))
    helper(1, days)
