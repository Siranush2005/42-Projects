#!/usr/bin/env python3

import sys


def create_dict(lst: list[str]) -> dict[str, int]:
    my_dict = {}

    for item in lst:
        key_value = item.split(':')

        if len(key_value) != 2:
            print(f"Error - invalid parameter '{item}'")
            continue

        key, value = key_value

        if key in my_dict:
            print(f"Redundant item '{key}' - discarding")
            continue

        try:
            quantity = int(value)
        except ValueError as v_e:
            print(f"Quantity error for '{key}': {v_e}")
            continue

        my_dict.update({key: quantity})

    return my_dict


if __name__ == "__main__":
    print("=== Inventory System Analysis ===")

    if len(sys.argv) == 1:
        print("No data provided")
    else:
        inventory_dict = create_dict(sys.argv[1:])

        print(f"Got inventory: {inventory_dict}")
        print(f"Item list: {list(inventory_dict.keys())}")

        total_quantity = sum(inventory_dict.values())
        print("Total quantity of the", end=" ")
        print(f"{len(inventory_dict)} items: {total_quantity}")

        for key in inventory_dict.keys():
            percentage = round(inventory_dict[key] / total_quantity * 100, 1)
            print(f"Item {key} represents {percentage}%")

        most_item = list(inventory_dict.keys())[0]
        least_item = list(inventory_dict.keys())[0]

        for item in inventory_dict.keys():
            if inventory_dict[most_item] < inventory_dict[item]:
                most_item = item
            if inventory_dict[least_item] > inventory_dict[item]:
                least_item = item

        print(f"Item most abundant: {most_item}", end=" ")
        print(f"with quantity {inventory_dict[most_item]}")

        print(f"Item least abundant: {least_item}", end=" ")
        print(f"with quantity {inventory_dict[least_item]}")

        inventory_dict.update({"magic_item": 1})
        print(f"Updated inventory: {inventory_dict}")
