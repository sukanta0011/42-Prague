from abc import ABC, abstractmethod
from typing import Any, Protocol
from datetime import datetime


class ProcessingStage():
    pass


class InputStage():
    def get_info(self) -> str:
        return "Input validation and parsing"

    def process(self, data: dict) -> Any:
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
        finally:
            return data

    def _process_json_data(self, data: dict) -> dict:
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
            unit = raw_data.get("unit")
            if unit is None or len(unit) == 0:
                data["error_msg"] = "Input: measurement unit unknown"
                return data
            return data
        else:
            data["error_msg"] = "Input: data is of unknown type"
            return data

    def _process_csv_data(self, data: dict) -> dict:
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

    def _process_stream_data(self, data: dict) -> dict:
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
        if valid_data / total_data < 0.6:
            data["error_msg"] = f"Input: {1 - valid_data * 100 / total_data}"
            "% of data has non numeric value"
        data["data"] = converted_data
        return data


class TransformStage():
    def get_info(self) -> str:
        return "Data transformation and enrichment"

    def process(self, data: dict) -> Any:
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
                data = self._process_stream(data, 15, 30)
                data["operation"] = "Transform: Aggregated and filtered"
            else:
                data["operation"] = "Transform: Unknown data type"
        except KeyError:
            data["error_msg"] = "Error: there is not 'data_format' " +\
                                "mentioned in provided data"
        finally:
            return data

    def _check_data_range(self, data: float, min: float, max: float) -> str:
        if data < min:
            return "Lower range"
        elif data > max:
            return "Upper range"
        else:
            return "Normal range"

    def _process_stream(self, data: dict, min: float, max: float) -> dict:
        filtered_data = [val for val in data['data'] if min < val < max]
        data_len = len(filtered_data)
        data["data"] = filtered_data
        data["len"] = data_len
        data["avg"] = round(sum(filtered_data) / data_len, 1)
        return data


class OutputStage():
    def get_info(self) -> str:
        return "Output formatting and delivery"

    def process(self, data: dict) -> Any:
        if data["data_format"] == "json":
            return self._process_json_data(data)
        elif data["data_format"] == "csv":
            return self._process_csv_data(data)
        elif data["data_format"] == "stream":
            return self._process_stream_data(data)

    def _process_json_data(self, data: dict) -> dict:
        data["operation"] = "Output: Processed temperature reading: " +\
            f"{data['data']['value']}°{data['data']['unit']}" +\
            f" ({data['range']})"
        return data

    def _process_csv_data(self, data: dict) -> dict:
        data["operation"] = "Output: User activity logged: 1 actions processed"
        return data

    def _process_stream_data(self, data: dict) -> dict:
        data["operation"] = f"Output: Stream summary: {data['len']} " +\
            f"readings, avg: {data['avg']}°C"
        return data


class ProcessPipeline(ABC):
    def __init__(self) -> None:
        self.stages = []

    def add_stage(self, stage: ProcessingStage) -> None:
        self.stages.append(stage)

    @abstractmethod
    def process(self, data: Any) -> Any:
        pass

    def _process_all_stages(self, data: dict) -> dict:
        for stage in self.stages:
            if data["error_msg"] is None:
                data = stage.process(data)
                print(data["operation"])
            else:
                print(data["error_msg"])
                break
        return data


class JSONAdapter(ProcessPipeline):
    def __init__(self, pipeline_id) -> None:
        super().__init__()
        self.id = pipeline_id

    def process(self, data):
        formatted_data = {
            "data_format": "json",
            "error_msg": None,
            "data": data
        }
        self._process_all_stages(formatted_data)


class CSVAdapter(ProcessPipeline):
    def __init__(self, pipeline_id):
        super().__init__()
        self.id = pipeline_id

    def process(self, data):
        formatted_data = {
                            "data_format": "csv",
                            "csv_data_types": ["user", "action", "timestamp"],
                            "error_msg": None,
                            "data": data
                        }
        self._process_all_stages(formatted_data)


class StreamAdapter(ProcessPipeline):
    def __init__(self, pipeline_id):
        super().__init__()
        self.id = pipeline_id

    def process(self, data):
        formatted_data = {
                            "data_format": "stream",
                            "error_msg": None,
                            "data": data
                        }
        self._process_all_stages(formatted_data)


class NexusManager():
    def __init__(self):
        self.pipelines = []

    def add_pipeline(self, pipeline: ProcessPipeline):
        self.pipelines.append(pipeline)

    def process_data(self):
        for pipeline in self.pipelines:
            pipeline.process()

    def get_processing_speed(self):
        return 1000


def tester():
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
    json_data = {"sensor": "temp", "value": 23.5, "unit": "C"}
    json_adapter.process(json_data)

    print("\nProcessing CSV data through same pipeline...")
    csv_adapter = CSVAdapter("csv_001")
    csv_adapter.add_stage(input_stage)
    csv_adapter.add_stage(transform_stage)
    csv_adapter.add_stage(output_stage)
    csv_data = "user1, login, 10:10"
    csv_adapter.process(csv_data)

    print("\nProcessing Stream data through same pipeline...")
    sensor_adapter = StreamAdapter("stream_001")
    sensor_adapter.add_stage(input_stage)
    sensor_adapter.add_stage(transform_stage)
    sensor_adapter.add_stage(output_stage)
    sensor_data = [10, 21, 20.5, 19, 30]
    sensor_adapter.process(sensor_data)

    print("=== Pipeline Chaining Demo ===")
    print("=== Error Recovery Test ===")


if __name__ == "__main__":
    tester()
