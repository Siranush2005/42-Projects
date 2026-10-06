#!/usr/bin/env python3

def garden_operations(operation_number: int) -> None:
    if operation_number == 0:
        int("abc")
    elif operation_number == 1:
        5 / 0
    elif operation_number == 2:
        open("/non/existent/file")
    elif operation_number == 3:
        "random_str" + 5


def helper_tester(i: int) -> None:
    print(f"Testing operation {i}...")
    try:
        garden_operations(i)
        print("Operation completed successfully")

    except ValueError as v_e:
        print(f"Caught ValueError: {v_e}")

    except ZeroDivisionError as z_d_e:
        print(f"Caught ZeroDivisionError: {z_d_e}")

    except FileNotFoundError as f_n_f_e:
        print(f"Caught FileNotFoundError: {f_n_f_e}")

    except TypeError as t_e:
        print(f"Caught TypeError: {t_e}")

    except Exception as e:
        print(f"Caught unexpected error: {e}")


def test_error_types() -> None:
    helper_tester(0)
    helper_tester(1)
    helper_tester(2)
    helper_tester(3)
    helper_tester(4)


if __name__ == "__main__":
    print("=== Garden Error Types Demo ===\n")
    test_error_types()
    print("\nAll error types tested successfully!")
