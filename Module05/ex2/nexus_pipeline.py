from abc import ABC, abstractmethod
from typing import List, Dict, Any, Union, Protocol


class ProcessingStage(Protocol):
    pass


class InputStage():
    def process(self, data: Any) -> Any:
        pass


class TransformStage():
    def process(self, data: Any) -> Any:
        pass


class OutputStage():
    def process(self, data: Any) -> Any:
        pass


class ProcessPipeline(ABC):
    def __init__(self):
        self.stages = []

    def add_stage(self, stage: ProcessingStage):
        self.stages.append(stage)
    

    @abstractmethod
    def process(self, data: Any) -> Any:
        pass


class JSONAdapter(ProcessPipeline):
    def __init__(self, pipeline_id):
        self.id = pipeline_id

    def process(self, data):
        pass


class CSVAdapter(ProcessPipeline):
    def __init__(self, pipeline_id):
        self.id = pipeline_id

    def process(self, data):
        pass

class StreamAdapter(ProcessPipeline):
    def __init__(self, pipeline_id):
        self.id = pipeline_id

    def process(self, data):
        pass

class NexusManager():
    pass