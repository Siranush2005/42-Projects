#!/usr/bin/env python3

import sys

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: ft_archive_creation.py <file>")
    else:
        file_name = sys.argv[1]

        print("=== Cyber Archives Recovery & Preservation ===")
        print(f"Accessing file '{file_name}'")

        try:
            file = open(file_name)
            try:
                data = file.read()
                print("---\n")
                print(data, end="")
                print("\n---")

            finally:
                file.close()
                print(f"File '{file_name}' closed.")

            transformed_data = ""
            for line in data.splitlines():
                transformed_data += line + "#\n"

            print("\nTransform data:")
            print("---\n")
            print(transformed_data, end="")
            print("\n---")

            new_file_name = input("Enter new file name (or empty): ")

            if new_file_name == "":
                print("Not saving data.")
            else:
                print(f"Saving data to '{new_file_name}'")

                new_file = open(new_file_name, "w")
                try:
                    new_file.write(transformed_data)
                finally:
                    new_file.close()

                print(f"Data saved in file '{new_file_name}'.")

        except OSError as error:
            print(f"Error opening file '{file_name}': {error}")
