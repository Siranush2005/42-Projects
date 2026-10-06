.PHONY: install run debug lint lint-strict test clean build

POETRY := poetry
PYTHON := $(POETRY) run python
MAIN := a_maze_ing.py
CONFIG := config.txt

install:
	$(POETRY) install

run:
	$(PYTHON) $(MAIN) $(CONFIG)

debug:
	$(PYTHON) -m pdb $(MAIN) $(CONFIG)

lint:
	$(POETRY) run flake8 .
	$(POETRY) run mypy . --warn-return-any --warn-unused-ignores --ignore-missing-imports \
		--disallow-untyped-defs --check-untyped-defs

lint-strict:
	$(POETRY) run flake8 .
	$(POETRY) run mypy mazegen a_maze_ing.py --strict

test:
	$(POETRY) run pytest tests/ -v

build:
	$(POETRY) build
	cp dist/mazegen-*.whl .

clean:
	find . -type d -name "__pycache__" -exec rm -rf {} +
	rm -rf .mypy_cache
	rm -rf .pytest_cache
	rm -rf .ruff_cache
	rm -rf build dist *.egg-info