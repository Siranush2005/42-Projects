from datetime import datetime
from typing import Optional, Any
from pydantic import BaseModel, Field, ValidationError


class SpaceStation(BaseModel):
    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=0.0, le=100.0)
    oxygen_level: float = Field(ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = True
    notes: Optional[str] = Field(default=None, max_length=200)


def print_station(station: SpaceStation) -> None:
    status = "Operational" if station.is_operational else "Offline"
    print("Valid station created:")
    print(f"ID: {station.station_id}")
    print(f"Name: {station.name}")
    print(f"Crew: {station.crew_size} people")
    print(f"Power: {station.power_level}%")
    print(f"Oxygen: {station.oxygen_level}%")
    print(f"Status: {status}")


if __name__ == "__main__":

    valid_station_data: dict[str, Any] = {
        "station_id": "ISS001",
        "name": "International Space Station",
        "crew_size": 6,
        "power_level": 85.5,
        "oxygen_level": 92.3,
        "last_maintenance": "2024-01-15T10:30:00",
        "is_operational": True,
        "notes": None,
    }

    invalid_station_data: dict[str, Any] = {
        "station_id": "ISS002",
        "name": "Overcrowded Station",
        "crew_size": 25,
        "power_level": 50.0,
        "oxygen_level": 80.0,
        "last_maintenance": "2024-01-15T10:30:00",
    }

    valid_station = SpaceStation(**valid_station_data)
    print_station(valid_station)

    print("\n========================================")
    print("Expected validation error:")

    try:
        invalid_station = SpaceStation(**invalid_station_data)
        print_station(valid_station)
    except ValidationError as v_e:
        first_error = v_e.errors()[0]
        print(first_error["msg"])
