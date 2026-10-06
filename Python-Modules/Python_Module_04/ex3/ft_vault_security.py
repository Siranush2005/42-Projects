#!/usr/bin/env python3

def secure_archive(
            file_name: str, op: str = 'r', msg: str = ""
        ) -> tuple[bool, str]:
    try:
        if op == 'r':
            with open(file_name, 'r') as f:
                content = f.read()
            return (True, content)

        elif op == 'w':
            with open(file_name, 'w') as f:
                f.write(msg)
            return (True, "Content successfully written to file")

        else:
            return (False, "Invalid operation")

    except OSError as os_e:
        return (False, f"{os_e}")


if __name__ == "__main__":
    print("=== Cyber Archives Security ===\n")

    print("Using 'secure_archive' to read from a nonexistent file")
    print(secure_archive("/not/existing/file", "r"))

    print("\nUsing 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("/etc/master.passwd", "r"))

    print("\nUsing 'secure_archive' to read from a regular file")
    print(secure_archive("my_file", "r"))

    print("\nUsing 'secure_archive' to write previous content to a new file:")
    print(
        secure_archive("new_file", "w", "New content for the new file")
    )
