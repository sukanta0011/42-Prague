from abc import ABC, abstractmethod
from typing import Any, List, Optional, Union, Dict


class DataStream(ABC):
    """Abstract class for data streaming"""
    def __init__(self, stream_id: str, type: str = "System Events") -> None:
        self.stream_id = stream_id
        self.data_type = type
        self.storage = {}
        self.counter = {}

    @abstractmethod
    def process_batch(self, data_batch: List[Any]) -> str:
        pass

    def filter_data(self, data_batch: List[Any],
                    criteria: Optional[str] = None) -> List[Any]:
        """Filter data based on provided criteria"""
        if not criteria:
            return data_batch
        return [data for data in data_batch if criteria in data]

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        """Return the id and type as dictionary"""
        return {"id": self.stream_id, "type": self.data_type}

    def _store_data_and_counts(self, data_batch: List[Any]) -> None:
        key = ""
        for data in data_batch:
            try:
                data = data.split(":")
                key = data[0].strip()
                self._store_in_counts(key)
                if len(data) > 1:
                    val = float(data[1].strip())
                    self._store_in_storage(key, val)
            except ValueError:
                print(f"Error: {data[1]} value for {key}" +
                      " is not number")
            except Exception as e:
                print(f"Error: {e}")

    def _store_in_counts(self, type: str) -> None:
        if type in self.counter.keys():
            self.counter[type] += 1
        else:
            self.counter[type] = 1

    def _store_in_storage(self, type: str, val: (int | float)) -> None:
        if type in self.storage.keys():
            self.storage[type] += val
        else:
            self.storage[type] = val

    def _get_number_of_data(self) -> int:
        total_data = 0
        for data in self.counter:
            total_data += self.counter[data]
        return total_data


class SensorStream(DataStream):
    """A class to process Sensor data"""
    def __init__(self, stream_id: str,
                 type: str = "Environmental Data") -> None:
        super().__init__(stream_id, type)
        self.storage = {
            "temp": 0,
            "humidity": 0,
            "pressure": 0,
        }
        self.counter = {
            "temp": 0,
            "humidity": 0,
            "pressure": 0,
        }

    def process_batch(self, data_batch: List[Any]) -> str:
        """Store the sensor data into separate category"""
        try:
            if not isinstance(data_batch, List):
                raise TypeError("Error: data type is not List")
        except Exception as e:
            print(f"Error: {e}")

        self._store_data_and_counts(data_batch)
        total_processes = self._get_number_of_data()
        return f"Sensor analysis: {total_processes} readings processed"

    def get_avg_temp(self) -> str:
        """Return the average temperature measured by the sensor"""
        try:
            if self.storage["temp"] > 0:
                avg_temp = self.storage["temp"] / self.counter["temp"]
                return f"avg temp: {avg_temp}°C"
            return "avg temp: no temperature data received yet"
        except KeyError:
            return f"Error: 'temp' is not in {self.storage.keys()}"
        except Exception as e:
            return f"Error: {e}"

    def filter_data(self, data_batch: List[Any],
                    criteria: Optional[str] = None) -> List[Any]:
        """Filter high sensors values"""
        if not criteria:
            return data_batch
        new_batch = []
        try:
            criteria_lst = criteria.split(",")
            max_temp = float(criteria_lst[0].strip())
            max_humidity = float(criteria_lst[1].strip())
            max_pressure = float(criteria_lst[2].strip())
            key = ""
            for data in data_batch:
                try:
                    key = data.split(":")[0].strip()
                    val = float(data.split(":")[1].strip())
                    if "temp" in key and val > max_temp:
                        new_batch.append(data)
                    elif "humidity" in key and val > max_humidity:
                        new_batch.append(data)
                    elif "pressure" in key and val > max_pressure:
                        new_batch.append(data)
                except ValueError:
                    print(f"Error: {data[1]} value for {key}" +
                          " is not number")
            return new_batch
        except ValueError:
            print(f"Error: criteria {criteria} are not in correct format")
        except Exception as e:
            print(f"Error: {e}")
        return new_batch


class TransactionStream(DataStream):
    """A class to process financial records"""
    def __init__(self, stream_id: str, type: str = "Financial Data") -> None:
        super().__init__(stream_id, type)
        self.storage = {
            "buy": 0,
            "sell": 0,
        }
        self.counter = {
            "buy": 0,
            "sell": 0,
        }

    def process_batch(self, data_batch: List[Any]) -> str:
        """Store the financial transaction into buy and sell category"""
        try:
            if not isinstance(data_batch, List):
                raise TypeError("Error: data type is not List")
        except TypeError as e:
            return (f"{e}")

        self._store_data_and_counts(data_batch)
        total_transaction = self._get_number_of_data()

        return f"Transaction analysis: {total_transaction} operations"

    def get_net_flow(self):
        """Return the net transactions"""
        try:
            flow = (self.storage["buy"] - self.storage["sell"])
            sign = "+"
            if flow < 0:
                sign = "-"
            return f"net flow {sign}{flow} units"
        except KeyError:
            return f"Error: 'buy/sell' is not in {self.storage.keys()}"
        except Exception as e:
            return f"Error: {e}"

    def filter_data(self, data_batch: List[Any],
                    criteria: Optional[str] = None) -> List[Any]:
        """Filter high transaction data only"""
        if not criteria:
            return data_batch
        new_batch = []
        try:
            high_trans = float(criteria.strip())
            key = ""
            for data in data_batch:
                try:
                    key = data.split(":")[0].strip()
                    val = float(data.split(":")[1].strip())
                    if val > high_trans:
                        new_batch.append(data)
                except ValueError:
                    print(f"Error: {data[1]} value for {key}" +
                          " is not number")
                except Exception as e:
                    print(f"Error: {e}")
            return new_batch
        except ValueError:
            print(f"Error: criteria {criteria} are not in correct format")
        except Exception as e:
            print(f"Error: {e}")
        return new_batch


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

        self._store_data_and_counts(data_batch)
        total_events = self._get_number_of_data()
        return f"Event analysis: {total_events} events"

    def get_event_counts(self, event: str) -> str:
        """Return the number of occurrence of provided event"""
        if event in self.counter.keys():
            return f"{self.counter[event]} {event} detected"
        return f"0 {event} detected"


class StreamProcessor():
    def __init__(self):
        self.stream_types = {}

    def add_stream_object(self, id: str, stream: DataStream) -> None:
        if id not in self.stream_types.keys():
            self.stream_types[id] = stream

    def display_stream_types(self) -> None:
        for key, val in self.stream_types.items():
            print(f"{key}: {val}")

    def process_all_stream(self, data: Dict[str, List[Any]]) -> None:
        for key in data:
            if key in self.stream_types.keys():
                results = self.stream_types[key].process_batch(data[key])
                print(f"- {results}")


def test_data_stream():
    """Testing data streaming"""
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
    trans = TransactionStream("TRANS_001", "Financial Data")
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
    print()
    batch_1 = {
        "SENSOR_001": ["temp:50", "humidity:65"],
        "TRANS_001": ["buy:500", "sell:150", "buy:75"],
        "EVENT_001": ["login", "error", "logout"]
    }
    all_streams = StreamProcessor()
    all_streams.add_stream_object("SENSOR_001", sensor)
    all_streams.add_stream_object("TRANS_001", trans)
    all_streams.add_stream_object("EVENT_001", event)
    print("Batch 1 Results:")
    all_streams.process_all_stream(batch_1)

    print()
    print("Stream filtering active: High-priority data only")
    sensor_data = ["temp:22.5", "humidity:135", "pressure:1013", "temp:40",
                   "humidity:65", "pressure:1013"]
    sensor_criteria = "30, 120, 1200"
    filter_sensor = sensor.filter_data(sensor_data, sensor_criteria)
    trans_data = ["buy:100", "sell:150", "buy:75", "sell: 1100"]
    trans_cri = "1000"
    filter_trans = trans.filter_data(trans_data, trans_cri)
    print(f"Filtered results: {len(filter_sensor)} critical sensor alerts, " +
          f"{len(filter_trans)} large transaction")

    print()
    print("All streams processed successfully. Nexus throughput optimal.")


if __name__ == "__main__":
    test_data_stream()
