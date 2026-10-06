#!/usr/bin/env python3

"""A-Maze-ing: maze generator, solver, exporter, and terminal viewer.

Entrypoint only. All generation, animation, and rendering logic lives in
the reusable maze package (see maze/app.py for the orchestration, and
maze/init.py for the standalone generator/solver API).
"""

import sys

from mazegen.app import run
from mazegen.config import ConfigError, load_config


if __name__ == "__main__":

    if len(sys.argv) != 2:
        print("Usage: python3 a_maze_ing.py <config_file>", file=sys.stderr)
        sys.exit(1)

    try:
        cfg = load_config(sys.argv[1])
    except ConfigError as exc:
        print(f"Error: {exc}", file=sys.stderr)
        sys.exit(1)

    try:
        run(cfg)
    except KeyboardInterrupt:
        print("\nInterrupted, exiting.")
        sys.exit(0)
