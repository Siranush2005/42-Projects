#!/usr/bin/env python3

def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    sorted_list: list[dict] = sorted(
        artifacts,
        key=lambda x: x["power"],
        reverse=True
    )
    return sorted_list


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    filtered_mages: list[dict] = list(
        filter(lambda x: x["power"] >= min_power, mages)
    )
    return filtered_mages


def spell_transformer(spells: list[str]) -> list[str]:
    transformed_spells: list[str] = list(
        map(lambda x: "* " + x + " *", spells)
    )
    return transformed_spells


def mage_stats(mages: list[dict]) -> dict:
    if not mages:
        return {
            "max_power": 0,
            "min_power": 0,
            "avg_power": 0.0
        }

    max_power: int = max(
        mages,
        key=lambda x: x["power"]
    )["power"]

    min_power: int = min(
        mages,
        key=lambda x: x["power"]
    )["power"]

    avg_power: float = round(
        sum(mage["power"] for mage in mages) / len(mages),
        2
    )

    return {
        "max_power": max_power,
        "min_power": min_power,
        "avg_power": avg_power
    }


if __name__ == "__main__":
    print("Testing artifact sorter...")

    artifacts = [
        {"name": "Crystal Orb", "power": 85},
        {"name": "Fire Staff", "power": 92},
        {"name": "Ice Wand", "power": 78}
    ]

    sorted_artifacts = artifact_sorter(artifacts)

    first = sorted_artifacts[0]
    second = sorted_artifacts[1]

    print(
        f"{first['name']} ({first['power']} power) comes before "
        f"{second['name']} ({second['power']} power)"
    )

    print("Testing spell transformer...")

    new_spells = ["fireball", "heal", "shield"]

    print(" ".join(spell_transformer(new_spells)))
