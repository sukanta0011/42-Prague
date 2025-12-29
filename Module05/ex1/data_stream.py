from abc import ABC, abstractmethod
from typing import Any, List, Optional, Union, Dict


class DataStream(ABC):
    """Abstract class for data streaming"""
    def __init__(self, stream_id: str, type: str) -> None:
        self.stream_id = stream_id
        self.data_type = type
        self.storage = {}

    @abstractmethod
    def process_batch(self, data_batch: List[Any]) -> str:
        pass

    def filter_data(self, data_batch: List[Any],
                    criteria: Optional[str] = None) -> List[Any]:
        pass

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return {"id": self.stream_id, "type": self.data_type}

    def _store_dat_in_dict(self, data_batch: List[Any]):
        for data in data_batch:
            try:
                data = data.split(":")
                key = data[0].strip()
                if key in self.storage.keys():
                    val = float(data[1].strip())
                    self.storage[key].append(val)
            except ValueError:
                print(f"Error: {data[1]} value for {key}" +
                      " is not number")

    def _get_number_of_data(self) -> int:
        total_data = 0
        for data in self.storage:
            total_data += len(self.storage[data])
        return (total_data)


class SensorStream(DataStream):
    """A class to process Sensor data"""
    def __init__(self, stream_id: str, type: str) -> None:
        super().__init__(stream_id, type)
        self.storage = {
            "temp": [],
            "humidity": [],
            "pressure": [],
        }

    def process_batch(self, data_batch: List[Any]) -> str:
        """Store the sensor data into separate category"""
        try:
            if not isinstance(data_batch, List):
                raise TypeError("Error: data type is not List")
        except TypeError as e:
            print(f"{e}")

        self._store_dat_in_dict(data_batch)
        total_processes = self._get_number_of_data()
        return f"Sensor analysis: {total_processes} readings processed"

    def get_avg_temp(self) -> str:
        """Return the average temperature measured by the sensor"""
        if len(self.storage["temp"]) > 0:
            avg_temp = sum(self.storage["temp"]) /\
                len(self.storage["temp"])
            return f"avg temp: {avg_temp}°C"
        return "avg temp: no temperature data received yet"


class TransactionStream(DataStream):
    """A class to process financial records"""
    def __init__(self, stream_id: str, type: str) -> None:
        super().__init__(stream_id, type)
        self.storage = {
            "buy": [],
            "sell": [],
        }

    def process_batch(self, data_batch: List[Any]) -> str:
        """Store the financial transaction into buy and sell category"""
        try:
            if not isinstance(data_batch, List):
                raise TypeError("Error: data type is not List")
        except TypeError as e:
            return (f"{e}")

        self._store_dat_in_dict(data_batch)
        total_transaction = self._get_number_of_data()

        return f"Transaction analysis: {total_transaction} operations"

    def get_net_flow(self):
        """Return the net transactions"""
        buy = 0
        sell = 0
        if (len(self.storage["buy"]) > 0):
            buy = sum(self.storage["buy"])
        if (len(self.storage["sell"]) > 0):
            sell = sum(self.storage["sell"])
        flow = int((buy - sell))
        sign = "+"
        if flow < 0:
            sign = "-"
        return f"net flow {sign}{flow} units"


class EventStream(DataStream):
    """A class to process the number of events"""
    def process_batch(self, data_batch: List[Any]) -> str:
        """Store unique events and increase the number of existing events and
           return the total number of events"""
        try:
            if not isinstance(data_batch, List):
                raise TypeError("Error: data type is not List")
        except TypeError as e:
            return (f"{e}")

        events = 0
        for data in data_batch:
            if data not in self.storage:
                self.storage[data] = 1
            else:
                self.storage[data] += 1
            events += 1

        return f"Event analysis: {events} events"

    def get_event_counts(self, event: str):
        """Return the number of occurrence of provided event"""
        if event in self.storage.keys():
            return f"{self.storage[event]} {event} detected"
        return f"0 {event} detected"


class StreamProcessor():
    pass


def test_data_stream():
    print("=== CODE NEXUS - POLYMORPHIC STREAM SYSTEM ===")
    print()
    print("Initializing Sensor Stream...")
    sensor = SensorStream("SENSOR_001", "Environmental Data")
    stream = sensor.get_stats()
    print(f"Stream ID: {stream['id']}, Type: {stream['type']}")
    data = ["temp:22.5", "humidity:65", "pressure:1013"]
    print(f"Processing sensor batch: [{', '.join(data)}]")
    data_processed = sensor.process_batch(data)
    avg_temp = sensor.get_avg_temp()
    print(f"{data_processed}, {avg_temp}")

    print()
    print("Initializing Transaction Stream...")
    trans = TransactionStream("TRANS_001", "Environmental Data")
    stream = trans.get_stats()
    print(f"Stream ID: {stream['id']}, Type: {stream['type']}")
    data = ["buy:100", "sell:150", "buy:75"]
    print(f"Processing transaction batch: [{', '.join(data)}]")
    operations = trans.process_batch(data)
    net_flow = trans.get_net_flow()
    print(f"{operations}, {net_flow}")

    print()
    print("Initializing Event Stream...")
    event = EventStream("EVENT_001", "System Events")
    stream = event.get_stats()
    print(f"Stream ID: {stream['id']}, Type: {stream['type']}")
    data = ["login", "error", "logout"]
    print(f"Processing event batch: [{', '.join(data)}]")
    total_events = event.process_batch(data)
    errors = event.get_event_counts("error")
    print(f"{total_events}, {errors}")
    print()

    print("=== Polymorphic Stream Processing ===")
    print("Processing mixed stream types through unified interface...")


if __name__ == "__main__":
    test_data_stream()
