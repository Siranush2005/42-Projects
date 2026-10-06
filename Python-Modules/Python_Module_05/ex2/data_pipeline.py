#!/usr/bin/env python3

from abc import ABC, abstractmethod
from typing import Any, Protocol
import typing


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

        return (index, val)


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


class ExportPlugin(Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        pass


class DataStream:
    def __init__(self) -> None:
        self._processors: list[DataProcessor] = []
        self._count = 0

    def register_processor(self, proc: DataProcessor) -> None:
        self._processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        for i in stream:
            is_ok = False

            for processor in self._processors:
                if processor.validate(i):
                    processor.ingest(i)
                    is_ok = True
                    break

            if not is_ok:
                print(
                    f"DataStream error - Can't process element in stream: {i}"
                )

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")

        if not self._processors:
            print("No processor found, no data")
            return

        for processor in self._processors:
            n = processor.__class__.__name__.replace("Processor", " Processor")
            print(f"{n}:", end=" ")
            print(f"total {processor._counter} items processed,", end=" ")
            print(f"remaining {len(processor._data)} on processor")

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for processor in self._processors:
            to_export: list[tuple[int, str]] = []

            for _ in range(nb):
                try:
                    to_export.append(processor.output())
                except Exception:
                    break

            plugin.process_output(to_export)


class CSVPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        print("CSV Output:")
        csv_output = ",".join(d[1] for d in data)
        print(csv_output)


class JSONPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        print("JSON Output:")

        json_list = []

        for i, val in data:
            json_list.append(f'"item_{i}": "{val}"')

        print("{" + ", ".join(json_list) + "}")


if __name__ == "__main__":
    print("=== Code Nexus - Data Pipeline ===\n")

    print("Initialize Data Stream...")
    stream = DataStream()
    stream.print_processors_stats()

    print("\nRegistering Processors")

    num = NumericProcessor()
    text = TextProcessor()
    log = LogProcessor()

    stream.register_processor(num)
    stream.register_processor(text)
    stream.register_processor(log)

    batch = [
        "Hello world",
        [3.14, -1, 2.71],
        [
            {"log_level": "WARNING",
             "log_message": "Telnet access! Use ssh instead"},
            {"log_level": "INFO", "log_message": "User wil is connected"}
        ],
        42,
        ["Hi", "five"]
    ]

    print("\nSend first batch of data on stream:", batch)
    stream.process_stream(batch)

    stream.print_processors_stats()

    print("\nSend 3 processed data from each processor to a CSV plugin:")
    csv_p = CSVPlugin()
    stream.output_pipeline(3, csv_p)

    print()

    stream.print_processors_stats()

    print("\nSend another batch of data")

    another_batch = [
        21,
        ["I love AI", "LLMs are wonderful", "Stay healthy"],
        [
            {
                "log_level": "ERROR",
                "log_message": "500 server crash",
            },
            {
                "log_level": "NOTICE",
                "log_message": "Certificate expires in 10 days",
            },
        ],
        [32, 42, 64, 84, 128, 168],
        "World hello",
    ]

    stream.process_stream(another_batch)

    stream.print_processors_stats()

    print("Send 5 processed data from each processor to a JSON plugin:")
    json_p = JSONPlugin()
    stream.output_pipeline(3, json_p)

    print()
    stream.print_processors_stats()
