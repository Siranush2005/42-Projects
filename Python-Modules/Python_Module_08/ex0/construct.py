import sys
import os
import site


def print_outside_status() -> None:
    print("MATRIX STATUS: You're still plugged in")
    print(f"\nCurrent Python: {sys.executable}")
    print("Virtual Environment: None detected")
    print("\nWARNING: You're in the global environment!")
    print("The machines can see everything you install.")
    print("\nTo enter the construct, run:")
    print("python -m venv matrix_env")
    print("source matrix_env/bin/activate # On Unix")
    print(R"matrix_env\Scripts\activate  # On Windows")
    print("\nThen run this program again.")


def print_inside_status() -> None:
    print("MATRIX STATUS: Welcome to the construct")
    print(f"\nCurrent Python: {sys.executable}")
    print(f"Virtual Environment: {os.path.basename(sys.prefix)}")
    print(f"Environment Path: {sys.prefix}")
    print("\nSUCCESS: You're in an isolated environment!")
    print("Safe to install packages without affecting")
    print("the global system.")
    print("\nPackage installation path:")
    print(site.getsitepackages()[0])


if __name__ == "__main__":
    if sys.prefix == sys.base_prefix:
        print_outside_status()
    else:
        print_inside_status()
