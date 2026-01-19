import sys


def convert_str_to_dict(string: str) -> list | None:
    """Validate and convert string input into dictionary"""
    key_val = string.split(":")
    if len(key_val) != 2:
        print(f"Invalid format: {string}")
        return None
    else:
        try:
            val = int(key_val[1])
        except ValueError:
            print(f"Error: '{key_val[1]}' is not integer")
            return None
        if key_val[0] is not None and len(key_val[0]) > 0:
            return [key_val[0], val]
        else:
            print(f"Error: '{key_val[0]}' is not string")
            return None


def parse_dict() -> dict | None:
    """Parse the cmd line input and store it as dictionary
       if in dictionary format"""
    item_dict = {}
    if len(sys.argv) > 1:
        for i in range(1, len(sys.argv)):
            item = convert_str_to_dict(sys.argv[i])
            if item is not None:
                if item[0] not in item_dict.keys():
                    item_dict[item[0]] = item[1]
                else:
                    item_dict[item[0]] += item[1]
        return item_dict
    else:
        print("No data provided. Usage: python3" +
              f" {sys.argv[0]} <item_name1:counts> <item_name2:counts> ...")
        return None


class InventoryManager:
    """Class to manage the provided dictionary"""
    def __init__(self, items: dict) -> None:
        self.items = items
        self.total_items = sum([v for _, v in self.items.items()])

    def summary(self) -> None:
        """Summarize the items"""
        print(f"Total items in inventory: {self.total_items}")
        print(f"Unique item types: {len(self.items)}")

    def detailed_list(self) -> None:
        """Show items in details with relative percentage"""
        sorted_items = sorted(self.items,
                              key=lambda x: self.items[x], reverse=True)
        for item in sorted_items:
            print(f"{item}: {self.items[item]} units"
                  f" ({(self.items[item] * 100 / self.total_items):.1f}%)")

    def stats(self) -> None:
        """Show most and least abundant item"""
        max_val, min_val = float("-inf"), float("inf")
        max_key, min_key = "", ""
        for k, v in self.items.items():
            if v > max_val:
                max_val = v
                max_key = k
            if v < min_val:
                min_val = v
                min_key = k

        print(f"Most abundant: {max_key} ({max_val} units)")
        print(f"Least abundant: {min_key} ({min_val} unit)")

    def categorize_by_supply(self) -> None:
        """Categorize the items based on the availability in the inventory"""
        enough = {}
        moderate = {}
        scarce = {}
        for k, v in self.items.items():
            if v >= 10:
                enough[k] = v
            elif 5 <= v < 10:
                moderate[k] = v
            else:
                scarce[k] = v
        print(f"Moderate: {moderate}")
        print(f"Scarce: {scarce}")

    def suggestion(self) -> list:
        """Return the list of item with only 1 left in stock"""
        restock = []
        for k, v in self.items.items():
            if v == 1:
                restock.append(k)
        return restock


if __name__ == "__main__":
    items = parse_dict()
    if items is not None:
        inventory_manager = InventoryManager(items)
        print("=== Inventory System Analysis ===")
        inventory_manager.summary()
        print("\n=== Current Inventory ===")
        inventory_manager.detailed_list()
        print("\n=== Inventory Statistics ===")
        inventory_manager.stats()
        print("\n=== Item Categories ===")
        inventory_manager.categorize_by_supply()
        print("\n=== Management Suggestions ===")
        print(f"Restock needed: {inventory_manager.suggestion()}")

        print("\n=== Dictionary Properties Demo ===")
        print(f"Dictionary keys: {list(items.keys())}")
        print(f"Dictionary values: {list(items.values())}")
        sample = "sword"
        print(f"Sample lookup - '{sample}' in inventory: "
              f"{sample in items.keys()}")
    else:
        print("Invalid items dictionary")
