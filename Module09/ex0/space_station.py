from datetime import datetime
from pydantic import BaseModel, Field, ValidationError
from typing import Optional


class SpaceStation(BaseModel):
    """Class to initialize space station with pydantic
       and Field to validate the entered data"""
    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=0.0, le=100.0)
    oxygen_level: float = Field(ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = True
    notes: Optional[str] = Field(default=None, max_length=200)


def show_station_details(id: str, name: str, crews: int,
                         power: float, oxygen: float, status: bool) -> None:
    """Show station detail in required formatting"""
    print(f"ID: {id}")
    print(f"Name: {name}")
    print(f"Crew: {crews} people")
    print(f"Power: {power}%")
    print(f"Oxygen: {oxygen}%")
    if status:
        print("Status: Operational")
    else:
        print("Status: Not Operational")


def main():
    """Testing the SpaceStation creation with different inputs"""
    data1 = {
        "station_id": "LGW125",
        "name": "Titan Mining Outpost",
        "crew_size": 6,
        "power_level": 76.4,
        "oxygen_level": 95.5,
        "last_maintenance": "2023-07-11T00:00:00",
        "is_operational": True,
        "notes": None
    }
    data2 = {
        "station_id": "LGW125",
        "name": "Titan Mining Outpost",
        "crew_size": 21,
        "power_level": 76.4,
        "oxygen_level": 95.5,
        "last_maintenance": "2023-07-11T00:00:00",
        "is_operational": True,
        "notes": None
    }
    print("Space Station Data Validation")
    print("========================================")
    print("Valid station created:")
    try:
        station1 = SpaceStation(**data1)
        show_station_details(station1.station_id, station1.name,
                             station1.crew_size, station1.power_level,
                             station1.oxygen_level, station1.is_operational)
    except ValidationError as e:
        print(e.errors()[0].get('msg'))
    
    print("\n========================================")
    print("Expected validation error:")
    try:
        station2 = SpaceStation(**data2)
        show_station_details(station2.station_id, station2.name,
                             station2.crew_size, station2.power_level,
                             station2.oxygen_level, station2.is_operational)
    except ValidationError as e:
        print(e.errors()[0].get('msg'))


if __name__ == "__main__":
    main()