from typing import Any, List
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    """Abstract class to validate, process and format the output"""
    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def process(self, data: Any) -> str:
        pass

    def format_output(self, result: str) -> str:
        return result


class NumericProcessor(DataProcessor):
    """Process Numerical data"""
    def validate(self, data: Any) -> bool:
        """Validate if the format of the data is List and data
           inside the list is numerical type or not"""
        if not isinstance(data, List):
            return False
        for val in data:
            if not isinstance(val, (int, float)):
                return False
        return True

    def process(self, data: Any) -> str:
        """Process the numerical data and calculate the average"""
        total_sum = 0
        total_len = len(data)
        try:
            for val in data:
                total_sum += val
            avg = total_sum / total_len
            return f"Processed {total_len} numerical values, "\
                   f"sum={total_sum}, avg={avg:0.1f}"
        except TypeError:
            return "Error: Data type is not int/float"
        except ZeroDivisionError:
            return "Error: No data received"
        except Exception as e:
            return f"Error: {e}"


class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        """Validate if the format of the data is string or not"""
        if not isinstance(data, str):
            return False
        return True

    def process(self, data: Any) -> str:
        """Process the string and count the words in the string"""
        try:
            words = data.split(" ")
            return "Processed text: "\
                   f"{len(data)} characters, {len(words)} words"
        except TypeError:
            return "Error: Data type is not string"
        except Exception as e:
            return f"Error: {e}"


class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        """Validate if the format of the data is string and
           has formatting TYPE: msg or not"""
        if not isinstance(data, str):
            return False
        if ":" not in data:
            return False
        return True

    def process(self, data: Any) -> str:
        """Split the log into log type and log message"""
        try:
            log = data.split(":")
            return f"{log[0].strip()} level "\
                   f"detected: {log[1].strip()}"
        except TypeError:
            return "Error: Data type is not string"
        except IndexError:
            return "Error: No log message found"
        except Exception as e:
            return f"Error: {e}"

    def format_output(self, result: str) -> str:
        """Formatting the output into required format"""
        if "ERROR" in result:
            return super().format_output(f"[ALERT] {result}")
        return super().format_output(f"[INFO] {result}")


def test_processor():
    data = [1, 2, 3, 4, 5]
    print("Initializing Numeric Processor...")
    numeric = NumericProcessor()
    print(f"Processing data: {data}")
    if (numeric.validate(data)):
        print("Validation: Numeric data verified")
        result = numeric.process(data)
        print(f"Output: {numeric.format_output(result)}")
    else:
        print("Validation: Numeric data verification failed")

    print()
    data = "Hello Nexus World"
    print("Initializing Text Processor...")
    text = TextProcessor()
    print(f"Processing data: {data}")
    if (text.validate(data)):
        print("Validation: Text data verified")
        result = text.process(data)
        print(f"Output: {text.format_output(result)}")
    else:
        print("Validation: Text data verification failed")

    print()
    data = "ERROR: Connection timeout"
    print("Initializing Log Processor...")
    log = LogProcessor()
    print(f"Processing data: {data}")
    if (log.validate(data)):
        print("Validation: Log entry verified")
        result = log.process(data)
        print(f"Output: {log.format_output(result)}")
    else:
        print("Validation: Log entry verification failed")

    print()
    print("=== Polymorphic Processing Demo ===")
    print("Processing multiple data types through same interface...")
    print(f"Result 1: {numeric.format_output(numeric.process([1, 2, 3]))}")
    print(f"Result 2: {text.format_output
                       (text.process('Hello World!'))}")
    print(f"Result 3: {log.format_output
                       (log.process('INFO: System ready'))}")
    print()
    print("Foundation systems online. Nexus ready for advanced streams.")


if __name__ == "__main__":
    print("=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===")
    print()
    test_processor()
