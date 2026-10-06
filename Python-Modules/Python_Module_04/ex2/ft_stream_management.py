#!/usr/bin/env python3

import sys

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
    else:
        file_name = sys.argv[1]

        print("=== Cyber Archives Recovery & Preservation ===")
        print(f"Accessing file '{file_name}'")

        try:
            try:
                file = open(file_name)

                data = file.read()
                print("---\n")
                print(data, end="")
                print("\n---")

            finally:
                file.close()
                print(f"File '{file_name}' closed.\n")

            transformed_data = ""
            for line in data.splitlines():
                transformed_data += line + "#\n"

            print("Transform data:")
            print("---\n")
            print(transformed_data, end="")
            print("\n---")

            print("Enter new file name (or empty): ", end="", flush=True)
            new_file_name = sys.stdin.readline().rstrip("\n")

            if new_file_name == "":
                print("Not saving data.")
            else:
                print(f"Saving data to '{new_file_name}'")

                try:
                    new_file = open(new_file_name, "w")
                    try:
                        new_file.write(transformed_data)
                    finally:
                        new_file.close()

                    print(f"Data saved in file '{new_file_name}'.")
                except OSError as error:
                    print(
                        f"[STDERR] Error opening file '{new_file_name}': "
                        f"{error}",
                        file=sys.stderr
                    )
                    print("Data not saved.")

        except OSError as error:
            print(
                f"[STDERR] Error opening file '{error.filename}': {error}",
                file=sys.stderr
            )
