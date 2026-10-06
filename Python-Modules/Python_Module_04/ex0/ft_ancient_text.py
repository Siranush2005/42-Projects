#!/usr/bin/env python3

import sys

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
    else:
        file_name = sys.argv[1]

        print("=== Cyber Archives Recovery ===")
        print(f"Accessing file '{file_name}'")

        try:
            file = open(file_name)

            try:
                print("---\n")
                print(file.read())
                print("---")
            finally:
                file.close()
                print(f"File '{file_name}' closed.")

        except OSError as os_error:
            print(f"Error opening file '{file_name}': {os_error}")
