#!/usr/bin/env python3

def input_temperature(temp_str: str) -> int:
    return int(temp_str)


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


if __name__ == "__main__":
    print("=== Garden Temperature ===\n")
    test_temperature()
    print("All tests completed - program didn't crash!")
