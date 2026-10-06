#!/usr/bin/env python3

# Check the isinstance(data, bool) case and return False.
# Otherwise, True (or 1) could be considered valid
# and processing would continue, even though a bool
# value should be treated as invalid.

from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):

    def __init__(self) -> None:
        self._data: list[str] = []
        self._counter: int = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if not self._data:
            raise Exception("No data available")

        val = self._data.pop(0)
        index = self._counter
        self._counter += 1

        return index, val


class NumericProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        lst = data if isinstance(data, list) else [data]
        return bool(lst) and all(
            not isinstance(x, bool)
            and isinstance(x, (int, float)) for x in lst
        )

    def ingest(
        self,
        data: int | float | list[int] | list[float] | list[int | float],
    ) -> None:
        if not self.validate(data):
            raise Exception("Improper numeric data")

        if isinstance(data, (int, float)):
            self._data.append(str(data))
        else:
            for item in data:
                self._data.append(str(item))


class TextProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        lst = data if isinstance(data, list) else [data]
        return bool(lst) and all(isinstance(s, str) for s in lst)

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise Exception("Improper text data")

        if isinstance(data, str):
            self._data.append(data)
        else:
            for item in data:
                self._data.append(item)


class LogProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        lst = data if isinstance(data, list) else [data]

        return (
            bool(lst)
            and all(
                isinstance(d, dict)
                and all(
                    isinstance(k, str) and isinstance(v, str)
                    for k, v in d.items()
                )
                for d in lst
            )
        )

    def ingest(
        self,
        data: dict[str, str] | list[dict[str, str]],
    ) -> None:
        if not self.validate(data):
            raise Exception("Improper log data")

        if isinstance(data, dict):
            log_str = (data["log_level"] + ": " + data["log_message"])
            self._data.append(log_str)
        else:
            for item in data:
                log_str = (item["log_level"] + ": " + item["log_message"])
                self._data.append(log_str)


if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===\n")

    print("Testing Numeric Processor...")
    num_proc = NumericProcessor()
    print(num_proc.validate(42))
    print(num_proc.validate("Hello"))

    print("Test invalid ingestion of string 'foo' without prior validation:")
    try:
        num_proc.ingest("foo")  # type: ignore
    except Exception as e:
        print(f"Got exception: {e}")

    num_data = [1, 2, 3, 4, 5]
    print(f"Processing data: {num_data}")
    num_proc.ingest(num_data)

    print("Extracting 3 values...")
    for _ in range(3):
        idx, val = num_proc.output()
        print(f"Numeric value {idx}: {val}")

    print("\nTesting Text Processor...")
    text_proc = TextProcessor()
    print(text_proc.validate(42))

    text_data = ["Hello", "Nexus", "World"]
    print(f"Processing data: {text_data}")
    text_proc.ingest(text_data)

    print("Extracting 1 value...")
    idx, val = text_proc.output()
    print(f"Text value {idx}: {val}")

    print("\nTesting Log Processor...")
    log_proc = LogProcessor()
    print(log_proc.validate("Hello"))

    log_data = [
        {"log_level": "NOTICE", "log_message": "Connection to server"},
        {"log_level": "ERROR", "log_message": "Unauthorized access!!"},
    ]
    print(f"Processing data: {log_data}")
    log_proc.ingest(log_data)

    print("Extracting 2 values...")
    for _ in range(2):
        idx, val = log_proc.output()
        print(f"Log entry {idx}: {val}")
