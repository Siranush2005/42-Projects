"""ASCII/Unicode terminal renderer for the maze.

Walls, the entry/exit markers, and the final shortest path all use the
same solid block glyph, just in different colours, so everything reads
as corridors carved through the maze rather than lines drawn on top of
it.
"""

import os

from mazegen.maze import Maze

_COLOR_PALETTE = [
    "\033[97m",  # white
    "\033[95m",  # pink
    "\033[92m",  # green
    "\033[96m",  # cyan
]
_RESET = "\033[0m"
_ENTRY_COLOR = "\033[33m"
_EXIT_COLOR = "\033[91m"
_PATH_COLOR = "\033[94m"

_WALL_CHAR = "\u2588"
_DIRECTION_DELTAS = {"N": (0, -1), "E": (1, 0), "S": (0, 1), "W": (-1, 0)}

Edge = tuple[str, int, int]
Coord = tuple[int, int]


def clear_screen() -> None:
    """Clear the terminal screen, used between animation frames."""
    os.system("cls" if os.name == "nt" else "clear")


def edge_between(a: Coord, b: Coord) -> Edge:
    """Identify the wall-gap segment crossed when moving from a to b.

    Args:
        a: (x, y) coordinates of the cell moved from.
        b: (x, y) coordinates of the neighbouring cell moved to.

    Returns:
        An ("h"|"v", x, y) tuple identifying the shared edge between the
        two cells, used internally to build the path corridor overlay.
    """
    ax, ay = a
    bx, by = b
    if ay == by:  # horizontal move -> vertical wall-gap segment
        return ("v", max(ax, bx), ay)
    return ("h", ax, max(ay, by))  # vertical move -> horizontal segment


def _build_corridor_overlay(
    sequence: list[Coord],
) -> tuple[set[Coord], set[Edge]]:
    """Compute the cells and wall-gap segments a cell sequence passes
    through, so it can be rendered as a continuous solid corridor.

    Args:
        sequence: Ordered sequence of (x, y) coordinates.

    Returns:
        A tuple of (cells, edges) covering the whole sequence.
    """
    cells: set[Coord] = set(sequence)
    edges: set[Edge] = {
        edge_between(sequence[i], sequence[i + 1])
        for i in range(len(sequence) - 1)
    }
    return cells, edges


def _horiz_wall(maze: Maze, x: int, y: int) -> bool:
    """Whether there is a horizontal wall above row y at column x."""
    if y < maze.height:
        return maze.get_cell(x, y).north
    return maze.get_cell(x, maze.height - 1).south


def _vert_wall(maze: Maze, x: int, y: int) -> bool:
    """Whether there is a vertical wall left of column x in row y."""
    if x < maze.width:
        return maze.get_cell(x, y).west
    return maze.get_cell(maze.width - 1, y).east


def _corner_present(maze: Maze, x: int, y: int) -> bool:
    """Whether a corner point (grid intersection) touches any wall segment."""
    touches_left = x > 0 and _horiz_wall(maze, x - 1, y)
    touches_right = x < maze.width and _horiz_wall(maze, x, y)
    touches_up = y > 0 and _vert_wall(maze, x, y - 1)
    touches_down = y < maze.height and _vert_wall(maze, x, y)
    return touches_left or touches_right or touches_up or touches_down


def render(
    maze: Maze,
    entry: Coord,
    exit_: Coord,
    path: list[Coord] | None = None,
    color_index: int = 0,
) -> str:
    """Render the maze using solid-block walls and coloured corridors.

    Layering, brightest (drawn last, wins) to dimmest:
        entry / exit markers > final path > empty corridor.

    Args:
        maze: The maze to render.
        entry: (x, y) entry coordinates.
        exit_: (x, y) exit coordinates.
        path: Optional ordered sequence of (x, y) coordinates from entry to
            exit (inclusive): the final shortest path, once known.
        color_index: Index into the wall colour palette (wraps around).

    Returns:
        A multi-line string representing the maze, ready to print.
    """
    wall_color = _COLOR_PALETTE[color_index % len(_COLOR_PALETTE)]
    wall_block = f"{wall_color}{_WALL_CHAR}{_RESET}"
    path_block = f"{_PATH_COLOR}{_WALL_CHAR}{_RESET}"
    entry_block = f"{_ENTRY_COLOR}{_WALL_CHAR}{_RESET}"
    exit_block = f"{_EXIT_COLOR}{_WALL_CHAR}{_RESET}"

    path_cells: set[Coord] = set()
    path_edges: set[Edge] = set()
    if path:
        path_cells, path_edges = _build_corridor_overlay(path)

    lines: list[str] = []

    for y in range(maze.height + 1):
        row_parts: list[str] = []
        for x in range(maze.width + 1):
            corner_glyph = (
                wall_block if _corner_present(maze, x, y) else " "
            )
            row_parts.append(corner_glyph)
            if x < maze.width:
                edge = ("h", x, y)
                if _horiz_wall(maze, x, y):
                    row_parts.append(wall_block * 2)
                elif edge in path_edges:
                    row_parts.append(path_block * 2)
                else:
                    row_parts.append("  ")
        lines.append("".join(row_parts))

        if y < maze.height:
            cell_parts: list[str] = []
            for x in range(maze.width + 1):
                edge = ("v", x, y)
                if _vert_wall(maze, x, y):
                    cell_parts.append(wall_block)
                elif edge in path_edges:
                    cell_parts.append(path_block)
                else:
                    cell_parts.append(" ")
                if x < maze.width:
                    cell = (x, y)
                    if cell == entry:
                        content = entry_block * 2
                    elif cell == exit_:
                        content = exit_block * 2
                    elif cell in path_cells:
                        content = path_block * 2
                    else:
                        content = "  "
                    cell_parts.append(content)
            lines.append("".join(cell_parts))

    return "\n".join(lines)


def path_to_cell_sequence(
    entry: Coord, path: list[str]
) -> list[Coord]:
    """Convert a direction-letter path into the ordered sequence of cells
    it visits, from entry to exit (both included).

    Args:
        entry: Starting (x, y) coordinates.
        path: List of direction letters ("N", "E", "S", "W").

    Returns:
        Ordered list of (x, y) coordinates, entry first, exit last.
    """
    x, y = entry
    cells = [(x, y)]
    for letter in path:
        dx, dy = _DIRECTION_DELTAS[letter]
        x, y = x + dx, y + dy
        cells.append((x, y))
    return cells
