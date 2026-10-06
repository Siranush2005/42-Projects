import alchemy.grimoire.dark_spellbook

if __name__ == "__main__":
    print("=== Kaboom 1 ===")
    print("Testing record dark spell: ", end="")
    print(
        alchemy.grimoire.dark_spellbook.dark_spell_record("Fan", "Bats")
    )  # type: ignore
