*This project has been created as part of the 42 curriculum by <sarakely>.*

# get_next_line

## Description

`get_next_line` is a function that reads and returns one line at a time from a file descriptor.

Each call returns the next line (including the newline `\n` if present). When there is nothing left to read, or an error occurs, the function returns `NULL`.

This implementation follows the 42 school requirements and focuses on:

* Low-level file I/O using `read()`
* Persistent memory via `static` variables
* Efficient string handling and dynamic allocation
* Proper memory management (no leaks)
* Support for multiple file descriptors (bonus)

## Prototype

char *get_next_line(int fd);

Parameter:

* fd: File descriptor to read from

Return value:

* A dynamically allocated string containing the next line
* NULL if EOF is reached or an error occurs

---

## Compilation

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

You can change the buffer size at compile time:

cc -D BUFFER_SIZE=1
cc -D BUFFER_SIZE=42
cc -D BUFFER_SIZE=1000

---

## Usage Example

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
int     fd;
char    *line;

```
fd = open("file.txt", O_RDONLY);
while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
close(fd);
```

}

---

## Core Logic

Static storage is used to keep leftover data between function calls.

Mandatory:
static char *storage;

Bonus:
static char *storage[1024];

Each file descriptor has its own independent storage in the bonus version.

---

## How It Works

1. Reading and Accumulating (read_and_join)

* Allocates a buffer of size BUFFER_SIZE + 1
* Reads from the file descriptor
* Appends the buffer to storage
* Continues until:

  * A newline `\n` is found, or
  * End of file is reached

Loop condition:
while (!ft_strchr(storage, '\n') && bytes > 0)

---

2. Extracting the Line (extract_line)

* If a newline exists:

  * Allocates and copies up to and including `\n`
* If no newline:

  * Returns the remaining string using ft_strdup

---

3. Cleaning the Storage (clean_storage)

* Finds the newline
* Keeps only the part after it
* Frees old storage

Mandatory version:

* Frees storage if no newline is found

Bonus version:

* Also frees if nothing remains after newline

Condition used:
if (!newline || !*(newline + 1))

---

## Memory Management

* Every allocation is paired with a free
* Old storage is always freed after joining
* Buffer is freed after each read cycle
* No memory leaks when used correctly

---

## Bonus — Multiple File Descriptors

The bonus version supports reading from multiple file descriptors simultaneously:

static char *storage[1024];

Each fd has its own independent buffer, allowing:

get_next_line(fd1);
get_next_line(fd2);
get_next_line(fd1);

without mixing data.

---

## Utility Functions Used

* ft_strlen   : Returns string length
* ft_strchr   : Finds a character in a string
* ft_strjoin  : Concatenates two strings
* ft_strdup   : Duplicates a string
* ft_strlcpy  : Safe string copy

---

## Key Features

* Handles any BUFFER_SIZE
* Works with files, stdin, and pipes
* Clean separation of logic into helper functions
* Robust error handling (read < 0, malloc failures)
* Bonus supports multiple file descriptors
* No memory leaks

---

## Notes

* If the file does not end with `\n`, the last line is still returned correctly.
* Partial lines are handled correctly.
* Storage always keeps only the necessary leftover data between calls.
