#!/usr/bin/env python3

def input_temperature(temp_str: str) -> int:
    t = int(temp_str)
    if t < 0:
        raise ValueError(f"{t}°C is too cold for plants (min 0°C)")
    if t > 40:
        raise ValueError(f"{t}°C is too hot for plants (max 40°C)")
    return t


def test_temperature() -> None:
    try:
        print("Input data is '25'")
        x = input_temperature("25")
        print(f"Temperature is now {x}°C")
    except ValueError as temperature_error:
        print(f"Caught input_temperature error: {temperature_error}")

    print()

    try:
        print("Input data is 'abc'")
        x = input_temperature("abc")
        print(f"Temperature is now {x}°C")
    except ValueError as temperature_error:
        print(f"Caught input_temperature error: {temperature_error}")

    print()

    try:
        print("Input data is '100'")
        x = input_temperature("100")
        print(f"Temperature is now {x}°C")
    except ValueError as temperature_error:
        print(f"Caught input_temperature error: {temperature_error}")

    print()

    try:
        print("Input data is '-50'")
        x = input_temperature("-50")
        print(f"Temperature is now {x}°C")
    except ValueError as temperature_error:
        print(f"Caught input_temperature error: {temperature_error}")

    print()


if __name__ == "__main__":
    print("=== Garden Temperature Checker ===\n")
    test_temperature()
    print("All tests completed - program didn't crash!")
