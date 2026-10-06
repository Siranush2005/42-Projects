*This project has been created as part of the 42 curriculum by hmnatsak, sarakely.*

# A-Maze-ing

## Description

A-Maze-ing is a Python application developed as part of the 42 curriculum. Its purpose is to **generate, solve, display, and export mazes** based on a user-provided configuration file.

The project is divided into two independent parts:

- **Application (`a_maze_ing.py`)** – reads a configuration file, validates it, generates a maze, solves it, renders it in the terminal, and exports it to a file.
- **Reusable package (`mazegen`)** – contains all maze-related functionality (configuration parsing, maze generation, solving, rendering, exporting, and utility functions) and can be imported independently into other Python projects.

The project emphasizes modular design, code reusability, configuration-driven execution, and maintainability.

---

## Features

- Configurable maze generation
- Perfect and non-perfect maze generation
- Deterministic generation using random seeds
- Configurable maze dimensions
- Maze solving using **Breadth-First Search (BFS)** or **A\* Search**
- Terminal rendering
- Optional maze generation animation
- Maze exporting to the required hexadecimal text format
- Reusable Python package
- Unit tests using pytest

---

## Project Structure

```text
.
├── a_maze_ing.py
├── config.txt
├── LICENSE.md
├── Makefile
├── maze.txt
├── maze_analyzer.py
├── pyproject.toml
├── README.md
├── requirements.txt
├── tests
│   ├── __init__.py
│   └── test_maze.py
└── mazegen
    ├── __init__.py
    ├── app.py
    ├── cell.py
    ├── config.py
    ├── exporter.py
    ├── generator.py
    ├── maze.py
    ├── renderer.py
    ├── solver.py
    └── utils.py
```

---

## Instructions

### Installation

Clone the repository:

```bash
git clone <repository_url>
cd A-Maze-ing
```

Install the project dependencies:

```bash
pip install -r requirements.txt
```

or

```bash
make install
```

### Running the Project

Run the application using a configuration file:

```bash
python3 a_maze_ing.py config.txt
```

or

```bash
make run
```

### Running the Tests

```bash
pytest
```

or

```bash
make test
```

### Available Makefile Commands

| Command | Description |
|----------|-------------|
| `make install` | Install project dependencies |
| `make run` | Run the application |
| `make debug` | Start the debugger |
| `make lint` | Run flake8 and mypy |
| `make clean` | Remove generated cache files |

---

## Configuration File

The application is configured using a plain-text configuration file.

Every non-empty line must follow the format:

```text
KEY=VALUE
```

- Blank lines are ignored.
- Lines beginning with `#` are treated as comments.

### Complete Configuration Example

```text
# Maze dimensions
WIDTH=20
HEIGHT=15

# Entry and exit coordinates
ENTRY=0,0
EXIT=19,14

# Output file
OUTPUT_FILE=maze.txt

# Generate a perfect maze
PERFECT=True

# Optional settings
SEED=42
ALGORITHM=BFS
MIN_LOOPS=2
ANIMATE=False
```

### Supported Configuration Keys

| Key | Type | Required | Description |
|------|------|----------|-------------|
| `WIDTH` | Integer | Yes | Maze width (1–40). |
| `HEIGHT` | Integer | Yes | Maze height (1–25). |
| `ENTRY` | `x,y` | Yes | Entry coordinates inside the maze. |
| `EXIT` | `x,y` | Yes | Exit coordinates inside the maze. |
| `OUTPUT_FILE` | String | Yes | Destination file for the exported maze. |
| `PERFECT` | Boolean | Yes | Generates a perfect maze when `True`. |
| `SEED` | Integer | No | Random seed. If omitted, one is generated automatically. |
| `ALGORITHM` | String | No | Solving algorithm. Supported values: `BFS` or `ASTAR`. |
| `MIN_LOOPS` | Integer | No | Minimum number of additional loops when generating a non-perfect maze. |
| `ANIMATE` | Boolean | No | Enables animated maze generation. |

### Configuration Validation

Before generating the maze, the parser validates that:

- all required keys are present;
- `WIDTH` and `HEIGHT` are positive integers;
- maze dimensions do not exceed **40 × 25**;
- `ENTRY` and `EXIT` are inside the maze boundaries;
- `ENTRY` and `EXIT` are different cells;
- boolean values are valid (`True`, `False`, `1`, `0`, `yes`, `no`);
- integer values are valid;
- `OUTPUT_FILE` is not empty;
- optional parameters contain valid values.

Any invalid configuration raises a `ConfigError` with a descriptive error message.

---

## Maze Generation Algorithm

The maze is generated using the **iterative Recursive Backtracker (Depth-First Search)** algorithm.

Instead of recursion, the implementation uses an explicit stack, avoiding Python recursion depth limitations while producing the same result.

The algorithm operates as follows:

1. Start from the initial cell.
2. Mark it as visited.
3. Randomly choose an unvisited neighboring cell.
4. Remove the wall between the two cells.
5. Continue exploring until there are no unvisited neighbors.
6. Backtrack using the stack until every reachable cell has been visited.

When `PERFECT=True`, the generated maze is a **perfect maze**, meaning there is exactly one path between any two reachable cells.

When `PERFECT=False`, additional passages are carved according to the configured `MIN_LOOPS` value, producing a non-perfect maze with multiple possible paths.

### Why This Algorithm?

The Recursive Backtracker algorithm was chosen because it:

- generates perfect mazes efficiently;
- has linear time complexity;
- is simple to understand and maintain;
- naturally produces long and visually interesting corridors;
- avoids recursion depth limitations by using an explicit stack;
- integrates cleanly with the loop-carving step used for non-perfect mazes, since walls can be removed independently after the perfect maze has been built.

---

## Maze Solving

After generation, the maze can be solved using one of two algorithms selected in the configuration file.

The project currently supports:

- **Breadth-First Search (BFS)**
- **A\* Search (ASTAR)**

Both algorithms always return the shortest path between the entry and the exit.

- **BFS** explores the maze level by level and guarantees the shortest path.
- **A\*** uses the Manhattan-distance heuristic, typically exploring fewer cells while still producing an optimal shortest path.

The solving implementation is completely independent of the maze generation algorithm.

---

## Reusable Module (`mazegen`)

The reusable part of the project is provided through the `mazegen` package, which can be imported into other Python applications without using the terminal interface.

| Module | Responsibility |
|--------|----------------|
| `config.py` | Parses and validates configuration files. |
| `cell.py` | Represents a single maze cell and its walls. |
| `maze.py` | Represents the maze grid built from cells. |
| `generator.py` | Implements the Recursive Backtracker generation algorithm. |
| `solver.py` | Implements BFS and A\* pathfinding. |
| `renderer.py` | Renders the maze to the terminal, optionally with animation. |
| `exporter.py` | Exports the maze to the hexadecimal text format. |
| `utils.py` | Shared helper functions used across the package. |
| `app.py` | Orchestrates configuration loading, generation, solving, rendering, and exporting for the CLI application. |

Example usage:

```python
from mazegen.generator import MazeGenerator

generator = MazeGenerator(width=20, height=15, seed=42)
generator.generate_perfect(0, 0)

maze = generator.maze
```

The resulting maze object can then be rendered, solved, exported, or further manipulated independently of the main application.

---

## Testing

Unit tests are implemented using **pytest** and cover configuration parsing, maze generation, and maze solving.

Run all tests with:

```bash
pytest
```

---

## Team and Project Management

### Roles of Each Team Member

**hmnatsak**
- Maze generation algorithm
- Core generation logic
- Project architecture
- Debugging and code review

**sarakely**
- Configuration parser
- Maze rendering
- Maze exporting
- Maze solving (BFS / A\*)
- Testing
- Documentation

### Anticipated Planning and How It Evolved

The initial development plan consisted of:

1. Designing the project architecture.
2. Creating reusable classes.
3. Implementing maze generation.
4. Implementing maze solving.
5. Implementing maze rendering.
6. Implementing maze exporting.
7. Writing unit tests.
8. Completing the documentation.

During development, the plan evolved as the team:

- reorganized the `mazegen` package into smaller, single-responsibility modules;
- strengthened configuration validation after discovering edge cases (e.g. entry/exit outside bounds);
- added configurable generation options (`SEED`, `MIN_LOOPS`, `ANIMATE`);
- added support for a second solving algorithm (A\*) in addition to BFS;
- improved error handling and error messages throughout the application.

### What Worked Well

- Clear separation between the application and the reusable package.
- Modular architecture, allowing each part to be developed and tested independently.
- Reusable components that can be imported without the CLI.
- Easy testing and maintenance thanks to small, focused modules.
- Robust configuration validation, catching invalid setups early.
- Independent maze generation and solving implementations.

### What Could Be Improved

Possible future improvements include:

- additional maze generation algorithms;
- more pathfinding algorithms;
- graphical visualization using a GUI library;
- animated maze solving;
- support for larger mazes;
- additional export formats.

### Tools Used

The following tools were used during development:

- **Python 3** – core implementation language
- **Git** – version control and collaboration
- **Make** – build/run/test automation
- **pytest** – unit testing
- **flake8** – linting and style checking
- **mypy** – static type checking
- **Visual Studio Code** – development environment

---

## Resources

### Documentation

The following external references were consulted, and each was used for a specific part of the project:

- **Python Documentation** – used to look up standard `argparse`/file-handling behavior and language features (e.g. exception handling, `pathlib`) while writing `config.py` and `a_maze_ing.py`.
- **Python Standard Library Documentation** – used to check the exact behavior of modules such as `random` (for seeded generation in `generator.py`), `heapq` (used in the A\* implementation in `solver.py`), and `collections.deque` (used for BFS's queue).
- **PEP 8 – Style Guide for Python Code** – followed throughout the codebase for naming conventions, line length, and formatting; used as the basis for the `flake8` configuration.
- **PEP 257 – Docstring Conventions** – used to write consistent docstrings across all `mazegen` modules and classes.
- **pytest Documentation** – used to learn fixtures, parametrization, and assertion patterns applied in `tests/test_maze.py`.
- **flake8 Documentation** – used to configure and interpret linting rules run via `make lint`.
- **mypy Documentation** – used to understand type-hint syntax and resolve type-checking errors surfaced by `make lint`.

### AI Usage

ChatGPT was used as a learning and development assistant throughout the project. It was used for:

- understanding Python language features and standard library modules (used while writing `mazegen/utils.py` and `mazegen/config.py`);
- discussing maze generation and pathfinding algorithms, including the trade-offs between the Recursive Backtracker, BFS, and A\* (used while designing `generator.py` and `solver.py`);
- reviewing object-oriented design decisions for the `mazegen` package structure;
- suggesting refactoring ideas, such as splitting the original monolithic script into the current modules;
- explaining debugging techniques for issues encountered in maze rendering and exporting;
- improving the wording and structure of this documentation (`README.md`).

All AI-generated suggestions and code examples were carefully reviewed, tested, modified when necessary, and fully understood before being incorporated into the final project.

---

## License

This project is distributed under the MIT License. See `LICENSE.md` for details.

---

## Authors

- hmnatsak
- sarakely