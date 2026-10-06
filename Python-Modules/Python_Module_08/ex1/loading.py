import sys
import importlib
import typing


REQUIRED_PACKAGES = {
    "numpy": "Numerical computation ready",
    "pandas": "Data manipulation ready",
    "matplotlib": "Visualization ready",
}

OPTIONAL_PACKAGES = {
    "requests": "Network access ready",
}


def check_dependency(module_name: str, purpose: str) -> bool:
    try:
        module = importlib.import_module(module_name)
        version = getattr(module, "__version__", "unknown")
        print(f"[OK] {module_name} ({version}) - {purpose}")
        return True
    except ImportError:
        print(f"[MISSING] {module_name} - {purpose}")
        return False


def print_install_instructions(missing: list[str]) -> None:
    print("\nMissing dependencies detected. Install them with:\n")
    print("  Using pip:")
    print("    $ pip install -r requirements.txt")
    print("\n  Using Poetry:")
    print("    $ poetry install")
    print(f"\n  Missing packages: {', '.join(missing)}")


def compare_package_versions() -> None:
    print("\n--- Dependency Management Comparison ---")
    print("pip:")
    print("  - Reads requirements.txt (flat list, no automatic lock file)")
    print("  - Version conflicts must be resolved manually")
    print("  - Relies on a manually created virtual environment")
    print("\nPoetry:")
    print("  - Reads pyproject.toml, resolves all constraints together")
    print("  - Generates poetry.lock for reproducible installs")
    print("  - Manages the virtual environment automatically")

    print("\nInstalled versions:")
    for name in list(REQUIRED_PACKAGES) + list(OPTIONAL_PACKAGES):
        try:
            module = importlib.import_module(name)
            version = getattr(module, "__version__", "unknown")
            print(f"  {name}: {version}")
        except ImportError:
            print(f"  {name}: not installed")


def generate_matrix_data(n_points: int = 1000) -> dict[str, typing.Any]:
    import numpy as np

    np.random.seed(42)
    return {
        "code_stream": np.random.randint(0, 2, n_points),
        "signal_strength": np.random.normal(50, 15, n_points),
        "anomaly_score": np.random.exponential(2, n_points),
    }


def analyze_data(n_points: int = 1000) -> typing.Any:
    import pandas as pd

    print("\nAnalyzing Matrix data...")
    print(f"Processing {n_points} data points...")
    df = pd.DataFrame(generate_matrix_data(n_points))
    print(df.describe())
    return df


def visualize_data(
        df: typing.Any, output_path: str = "matrix_analysis.png"
        ) -> None:
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt

    print("Generating visualization...")
    fig, axes = plt.subplots(1, 2, figsize=(12, 5))
    axes[0].hist(df["signal_strength"], bins=30, color="green")
    axes[0].set_title("Signal Strength Distribution")
    axes[1].scatter(
        df.index, df["anomaly_score"], s=5, color="darkgreen", alpha=0.5
        )
    axes[1].set_title("Anomaly Score Over Time")
    plt.tight_layout()
    plt.savefig(output_path)
    plt.close(fig)
    print(f"Analysis complete! Results saved to: {output_path}")


if __name__ == "__main__":
    print("LOADING STATUS: Loading programs...")
    print("Checking dependencies:")

    missing = []
    for name, purpose in REQUIRED_PACKAGES.items():
        if not check_dependency(name, purpose):
            missing.append(name)
    for name, purpose in OPTIONAL_PACKAGES.items():
        check_dependency(name, purpose)

    if missing:
        print_install_instructions(missing)
        sys.exit(1)

    df = analyze_data(1000)
    visualize_data(df)
    compare_package_versions()
