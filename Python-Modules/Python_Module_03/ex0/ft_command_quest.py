import sys

i = 1
argv_len = len(sys.argv)

print("=== Command Quest ===")
print(f"Program name: {sys.argv[0]}")

if argv_len == 1:
    print("No arguments provided!")
else:
    print(f"Arguments received: {argv_len - 1}")
    while i < argv_len:
        print(f"Argument {i}: {sys.argv[i]}")
        i += 1

print(f"Total arguments: {argv_len}")

# args = sys.argv[1:]
# we can use slicing method to shorten the code
