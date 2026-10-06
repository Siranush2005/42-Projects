"""Configuration file parsing and validation for A-Maze-ing."""

import random
from typing import TypedDict


class ConfigError(Exception):
    """Raised when the configuration file is invalid."""


class ConfigDict(TypedDict):
    """Validated maze configuration, as returned by load_config."""

    width: int
    height: int
    entry: tuple[int, int]
    exit: tuple[int, int]
    output_file: str
    perfect: bool
    seed: int
    animate: bool
    algorithm: str
    min_loops: int


_REQUIRED_KEYS = {"WIDTH", "HEIGHT", "ENTRY", "EXIT", "OUTPUT_FILE", "PERFECT"}
_ALGORITHMS = {"BFS", "ASTAR"}
_DEFAULT_ALGORITHM = "BFS"
_DEFAULT_MIN_LOOPS = 2


def _parse_lines(path: str) -> dict[str, str]:
    """Read KEY=VALUE lines from a config file into a dict.

    Args:
        path: Path to the configuration file.

    Returns:
        Raw (unparsed) string values, keyed by upper-cased key. Blank
        lines and lines starting with '#' are skipped.

    Raises:
        ConfigError: If the file can't be read, or a line is malformed.
    """
    raw: dict[str, str] = {}
    try:
        with open(path, "r", encoding="utf-8") as f:
            for line_number, line in enumerate(f, start=1):
                stripped = line.strip()
                if not stripped or stripped.startswith("#"):
                    continue
                if "=" not in stripped:
                    raise ConfigError(
                        f"{path}:{line_number}: invalid line "
                        f"'{stripped}' (expected KEY=VALUE)"
                    )
                key, _, value = stripped.partition("=")
                raw[key.strip().upper()] = value.strip()
    except FileNotFoundError as e:
        raise ConfigError(f"Configuration file not found: {path}") from e
    except OSError as e:
        raise ConfigError(
            f"Could not read configuration file {path}: {e}"
        ) from e
    return raw


def _parse_coord(raw_value: str, key: str) -> tuple[int, int]:
    """Parse an 'x,y' string into a coordinate tuple."""
    parts = raw_value.split(",")
    if len(parts) != 2:
        raise ConfigError(
            f"{key} must be in the form x,y (not '{raw_value}')"
        )
    try:
        return (int(parts[0]), int(parts[1]))
    except ValueError as e:
        raise ConfigError(
            f"{key} coordinates must be integers (not '{raw_value}')"
        ) from e


def _parse_bool(raw_value: str, key: str) -> bool:
    """Parse a boolean-ish string (true/false, 1/0, yes/no, any case)."""
    normalized = raw_value.strip().lower()
    if normalized in ("true", "1", "yes"):
        return True
    if normalized in ("false", "0", "no"):
        return False
    raise ConfigError(f"{key} must be a boolean (not '{raw_value}')")


def load_config(path: str) -> ConfigDict:
    """Read and validate a maze configuration file.

    Args:
        path: Path to the configuration file.

    Returns:
        A validated configuration dict.

    Raises:
        ConfigError: If the file is missing, malformed, or has invalid
            values.
    """
    raw = _parse_lines(path)

    missing = _REQUIRED_KEYS - raw.keys()
    if missing:
        raise ConfigError(
            f"Missing required key(s): {', '.join(sorted(missing))}"
        )

    try:
        width = int(raw["WIDTH"])
        height = int(raw["HEIGHT"])
    except ValueError as e:
        raise ConfigError("WIDTH and HEIGHT must be integers") from e
    if width <= 0 or height <= 0:
        raise ConfigError("WIDTH and HEIGHT must be positive integers")

    entry = _parse_coord(raw["ENTRY"], "ENTRY")
    exit_ = _parse_coord(raw["EXIT"], "EXIT")
    for name, (x, y) in (("ENTRY", entry), ("EXIT", exit_)):
        if not (0 <= x < width and 0 <= y < height):
            raise ConfigError(f"{name} {x},{y} is outside the maze bounds")
    if entry == exit_:
        raise ConfigError("ENTRY and EXIT must be different cells")

    perfect = _parse_bool(raw["PERFECT"], "PERFECT")

    output_file = raw["OUTPUT_FILE"]
    if not output_file:
        raise ConfigError("OUTPUT_FILE must not be empty")

    if "SEED" in raw:
        try:
            seed = int(raw["SEED"])
        except ValueError as e:
            raise ConfigError("SEED must be an integer") from e
    else:
        seed = random.randint(0, 999_999)
        print(f"No SEED given, using generated seed: {seed}")

    algorithm = _DEFAULT_ALGORITHM
    if "ALGORITHM" in raw:
        algorithm = raw["ALGORITHM"].strip().upper()
        if algorithm not in _ALGORITHMS:
            raise ConfigError(
                f"ALGORITHM must be one of {sorted(_ALGORITHMS)} "
                f"(not '{algorithm}')"
            )

    min_loops = _DEFAULT_MIN_LOOPS
    if "MIN_LOOPS" in raw:
        try:
            min_loops = int(raw["MIN_LOOPS"])
        except ValueError as e:
            raise ConfigError("MIN_LOOPS must be an integer") from e
        if min_loops < 1:
            raise ConfigError("MIN_LOOPS must be at least 1")

    animate = False
    if "ANIMATE" in raw:
        animate = _parse_bool(raw["ANIMATE"], "ANIMATE")

    return {
        "width": width,
        "height": height,
        "entry": entry,
        "exit": exit_,
        "output_file": output_file,
        "perfect": perfect,
        "seed": seed,
        "animate": animate,
        "algorithm": algorithm,
        "min_loops": min_loops,
    }
