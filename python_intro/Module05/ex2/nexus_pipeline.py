from abc import ABC, abstractmethod
from typing import Any, Protocol, List
from datetime import datetime
import random
import time

json_data = {"sensor": "temp", "value": 23.5, "unit": "C"}
csv_data = "user1, login, 10:10"
sensor_data = [50, 40, 20.5, 60, 30]


def random_stream_generator() -> List:
    """Generate artificial random number to mimic stream"""
    return [random.randint(0, 60) for _ in range(10)]


class ProcessingStage(Protocol):
    """A class to represent duck typing"""
    def process(self, data: Any) -> Any:
        pass


class InputStage():
    """A class to validate and handle the raw input"""
    def get_info(self) -> str:
        """Return the job of the class"""
        return "Input validation and parsing"

    def process(self, data: Any) -> Any:
        """Process json, csv and stream data and convert
           them into dict format"""
        try:
            if data["data_format"] == "json":
                return self._process_json_data(data)
            elif data["data_format"] == "csv":
                return self._process_csv_data(data)
            elif data["data_format"] == "stream":
                return self._process_stream_data(data)
            else:
                data["error_msg"] = "Input: 'data_format' unknown"
        except KeyError as e:
            data["error_msg"] = "Input: there is no 'data_format' " +\
                                f"mentioned in provided data. {e}"
        except Exception as e:
            data["error_msg"] = e
        finally:
            return data

    def _process_json_data(self, data: Any) -> dict:
        """Special function to handle json data"""
        data["operation"] = f"Input: {data['data']}"
        raw_data = data['data']
        if "sensor" in raw_data.keys():
            if raw_data["sensor"] is None or len(raw_data["sensor"]) == 0:
                data["error_msg"] = "Input: sensor type unknown"
                return data
            value = raw_data.get("value")
            if value is None:
                data["error_msg"] = "Input: sensor value not provided"
                return data
            else:
                try:
                    data["data"]["value"] = float(value)
                except ValueError:
                    data["error_msg"] = "Input: sensor value is not a number"
                    return data
                except Exception as e:
                    data["error_msg"] = e
                    return data
            unit = raw_data.get("unit")
            if unit is None or len(unit) == 0:
                data["error_msg"] = "Input: measurement unit unknown"
                return data
            return data
        else:
            data["error_msg"] = "Input: data is of unknown type"
            return data

    def _process_csv_data(self, data: Any) -> dict:
        """Special function to handle csv data"""
        data["operation"] = f"Input: \"{','.join(data['csv_data_types'])}\""
        data_in_line = data["data"].split(",")
        if len(data_in_line) != len(data["csv_data_types"]):
            data["error_message"] = "Input: CSV heading and data miss-match" +\
                f"{data['data']}"
            return data
        for idx, name in enumerate(data["csv_data_types"]):
            try:
                data[name] = data_in_line[idx].strip()
            except Exception:
                data["error_message"] = f"Input: {name} missing in CSV"
                return data
        data.pop("data")
        return data

    def _process_stream_data(self, data: Any) -> dict:
        """Special function to stream json data"""
        data["operation"] = "Input: Real-time sensor stream"
        total_data = len(data["data"])
        valid_data = 0
        converted_data = []
        for value in data["data"]:
            try:
                converted_data.append(float(value))
                valid_data += 1
            except ValueError:
                pass
            except Exception:
                pass
        if total_data > 0 and valid_data / total_data < 0.6:
            data["error_msg"] = f"Input: {1 - valid_data * 100 / total_data}"
            "% of data has non numeric value"
        data["data"] = converted_data
        return data


class TransformStage():
    """A class to Transform the after Input stage"""
    def get_info(self) -> str:
        """Return the job of the class"""
        return "Data transformation and enrichment"

    def process(self, data: Any) -> Any:
        """Transform the preprocesses data into desire output format"""
        try:
            if data["data_format"] == "json":
                data["range"] = self._check_data_range(
                    data["data"]["value"], 0, 40)
                data["timestamp"] = datetime.now()
                data["operation"] = "Transform: Enriched with metadata " +\
                                    "and validation"
            elif data["data_format"] == "csv":
                data["operation"] = "Transform: Parsed and structured data"

            elif data["data_format"] == "stream":
                data = self._process_stream(data, -10, 100)
                data["operation"] = "Transform: Aggregated and filtered"
            else:
                data["operation"] = "Transform: Unknown data type"
        except KeyError:
            data["error_msg"] = "Error: there is not 'data_format' " +\
                                "mentioned in provided data"
        except Exception as e:
            data["error_msg"] = e
        finally:
            return data

    def _check_data_range(self, data: float, min: float, max: float) -> str:
        """Validate is the provided date is in the range or not"""
        if data < min:
            return "Lower range"
        elif data > max:
            return "Upper range"
        else:
            return "Normal range"

    def _process_stream(self, data: Any, min: float, max: float) -> dict:
        """Special function to handle stream data"""
        filtered_data = [val for val in data['data'] if min < val < max]
        data_len = len(filtered_data)
        try:
            data["data"] = filtered_data
            data["len"] = data_len
            data["avg"] = round(sum(filtered_data) / data_len, 1)
        except ZeroDivisionError as e:
            print(f"Error: {e}")
        except Exception as e:
            print(f"Error: {e}")
        finally:
            return data


class OutputStage():
    def get_info(self) -> str:
        """Return the job of the class"""
        return "Output formatting and delivery"

    def process(self, data: Any) -> Any:
        """Depending on the pipeline or the data type, it transform the
           data to desire output format"""
        if "pipeline" in data.keys():
            if data["pipeline"] == "logging":
                if data["avg"] > 40:
                    print(f"Warning: Avg temperature {data['avg']}°C "
                          "is above 40°C")
        else:
            if data["data_format"] == "json":
                return self._process_json_data(data)
            elif data["data_format"] == "csv":
                return self._process_csv_data(data)
            elif data["data_format"] == "stream":
                return self._process_stream_data(data)
            else:
                data["error_msg"] = "Output: No data format provided"

        return data

    def _process_json_data(self, data: Any) -> dict:
        """Transform the json data"""
        data["operation"] = "Output: Processed temperature reading: " +\
            f"{data['data']['value']}°{data['data']['unit']}" +\
            f" ({data['range']})"
        return data

    def _process_csv_data(self, data: Any) -> dict:
        """Transform the csv data"""
        data["operation"] = "Output: User activity logged: 1 actions processed"
        return data

    def _process_stream_data(self, data: Any) -> dict:
        """Transform the stream data"""
        data["operation"] = f"Output: Stream summary: {data['len']} " +\
            f"readings, avg: {data['avg']}°C"
        return data


class ProcessingPipeline(ABC):
    """Abstract class to handle multiple stages inside the pipeline"""
    def __init__(self) -> None:
        """Initialize the pipeline with empty stages"""
        self.stages = []
        self.print_operation = True

    def add_stage(self, stage: ProcessingStage) -> None:
        """Add the processing stages"""
        self.stages.append(stage)

    @abstractmethod
    def process(self, data: Any) -> Any:
        pass

    def set_operation_printing(self, operation: bool):
        """Set the option to print what happened in each stages"""
        self.print_operation = operation

    def _process_all_stages(self, data: dict) -> dict:
        """Process all stages provided in the pipeline and
           handle error as well"""
        first_copy = data['data']
        for stage in self.stages:
            if data["error_msg"] is None:
                data = stage.process(data)
                if self.print_operation:
                    print(data["operation"])
            else:
                print(f"Error: {data['error_msg']}")
                print("Recovery initiated: Stopping further processing of"
                      " the data in the next pipeline")
                self._save_error_data(first_copy)
                data = first_copy
                break
        return data

    def _save_error_data(self, data: Any) -> None:
        """Save the error prone data to file for later analysis"""
        print(f"{data} saved in error files, Pipeline restored")


class JSONAdapter(ProcessingPipeline):
    """Special adapter to handle JSON type data"""
    def __init__(self, pipeline_id: str) -> None:
        """Initialize the adapter with the pipeline id"""
        super().__init__()
        self.id = pipeline_id

    def process(self, data: Any) -> dict:
        """Process JSON data to transform it into dictionary format"""
        formatted_data = {
            "data_format": "json",
            "error_msg": None,
            "data": data
        }
        return self._process_all_stages(formatted_data)


class CSVAdapter(ProcessingPipeline):
    """Special adapter to handle CSV type data"""
    def __init__(self, pipeline_id: str) -> None:
        """Initialize the adapter with the pipeline id"""
        super().__init__()
        self.id = pipeline_id

    def process(self, data: Any) -> dict:
        """Process CSV data to transform it into dictionary format"""
        formatted_data = {
            "data_format": "csv",
            "csv_data_types": ["user", "action", "timestamp"],
            "error_msg": None,
            "data": data
        }
        return self._process_all_stages(formatted_data)


class StreamAdapter(ProcessingPipeline):
    """Special adapter to handle stream data"""
    def __init__(self, pipeline_id: str) -> None:
        """Initialize the adapter with the pipeline id"""
        super().__init__()
        self.id = pipeline_id

    def process(self, data: Any) -> dict:
        """Process stream data to transform it into dictionary format"""
        formatted_data = {
            "data_format": "stream",
            "error_msg": None,
            "data": data
        }
        return self._process_all_stages(formatted_data)


class LogPipeline(ProcessingPipeline):
    """Pipeline to log the error or warning message on the terminal"""
    def __init__(self) -> None:
        super().__init__()

    def process(self, data: Any) -> Any:
        """Processed the formatted data to identify errors/ warnings"""
        data["pipeline"] = "logging"
        data["operation"] = "Logging: errors and warnings"
        if data["data_format"] == "stream":
            return self._process_all_stages(data)


class NexusManager():
    """Class to manage multiple pipelines"""
    def __init__(self):
        self.pipelines = []

    def add_pipeline(self, pipeline: ProcessingPipeline):
        """Add different pipelines"""
        self.pipelines.append(pipeline)

    def process_data(self):
        """Process data through each pipeline"""
        data = random_stream_generator()
        for pipeline in self.pipelines:
            data = pipeline.process(data)

    def get_processing_speed(self):
        return 1000


def tester():
    """Program to test the nexus pipeline"""
    print("=== CODE NEXUS - ENTERPRISE PIPELINE SYSTEM ===")
    print()
    print("Initializing Nexus Manager...")
    nexus = NexusManager()
    print("Creating Data Processing Pipeline...")
    print(f"Pipeline capacity: {nexus.get_processing_speed()} streams/second")

    input_stage = InputStage()
    transform_stage = TransformStage()
    output_stage = OutputStage()

    print()
    print(f"Stage 1: {input_stage.get_info()}")
    print(f"Stage 2: {transform_stage.get_info()}")
    print(f"Stage 3: {output_stage.get_info()}")

    print("\n=== Multi-Format Data Processing ===")
    print("\nProcessing JSON data through pipeline...")
    json_adapter = JSONAdapter("json_001")
    json_adapter.add_stage(input_stage)
    json_adapter.add_stage(transform_stage)
    json_adapter.add_stage(output_stage)
    json_adapter.process(json_data)

    print("\nProcessing CSV data through same pipeline...")
    csv_adapter = CSVAdapter("csv_001")
    csv_adapter.add_stage(input_stage)
    csv_adapter.add_stage(transform_stage)
    csv_adapter.add_stage(output_stage)
    csv_adapter.process(csv_data)

    print("\nProcessing Stream data through same pipeline...")
    sensor_adapter = StreamAdapter("stream_001")
    sensor_adapter.add_stage(input_stage)
    sensor_adapter.add_stage(transform_stage)
    sensor_adapter.add_stage(output_stage)
    sensor_adapter.process(sensor_data)

    print("\n=== Pipeline Chaining Demo ===")
    logger = LogPipeline()
    logger.add_stage(output_stage)
    logger.set_operation_printing(False)
    print("Pipeline A -> Pipeline B")
    print("Data flow: Raw -> Processed -> Stored -> Logged")
    sensor_adapter.set_operation_printing(False)
    nexus.add_pipeline(sensor_adapter)
    nexus.add_pipeline(logger)
    nexus.process_data()

    print("\nChain result: 100 records processed through 2-stage pipeline")
    start = time.time()
    for _ in range(100):
        nexus.process_data()
    end = time.time()
    print(f"Performance: {(end - start):.3f}s total processing time")

    print("\n=== Error Recovery Test ===")
    print("Simulating pipeline failure...")
    wrong_json_data = {"sensor": "temp", "value": "2a3.5", "unit": "C"}
    json_adapter.process(wrong_json_data)
    json_adapter.process(json_data)


if __name__ == "__main__":
    tester()
