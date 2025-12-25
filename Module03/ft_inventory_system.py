class PlayerInventoryManager:
    """A class to manage the inventory of the players"""

    def __init__(self, data: dict = {}) -> None:
        """Initialize with the existing player information"""
        self.players = data

    def show_catalogs(self):
        """Show the list of register items"""
        try:
            all_catalogs = self.players['catalog']
            if len(all_catalogs) > 0:
                for key, value in all_catalogs.items():
                    print(key, value)
            else:
                print("Catalog is empty.")
        except KeyError:
            print("KeyError: There is no key name 'catalog' in dictionary")

    def show_players_details(self):
        """Show the details of registered players"""
        try:
            all_players = self.players['players']
            if len(all_players) > 0:
                for key, value in all_players.items():
                    print(key, value)
            else:
                print("There is no player in the registered")
        except KeyError:
            print("KeyError: There is no key name 'players' in dictionary")

    def _get_item_type(self, item_name: str) -> str:
        category = self.players['catalog']
        return category.get(item_name).get('type')

    def _get_item_rarity(self, item_name: str) -> str:
        category = self.players['catalog']
        return category.get(item_name).get('rarity')

    def _get_item_value(self, item_name: str) -> int:
        category = self.players['catalog']
        price = 0
        try:
            price = int(category.get(item_name).get('value'))
        except ValueError:
            print(f"ValueError: {category.get(item_name).get('value')} is" +
                  " not number")
        return (price)

    def _display_item_in_format(self, name, quantity) -> None:
        try:
            quant = int(quantity)
            type = self._get_item_type(name)
            rarity = self._get_item_rarity(name)
            value = self._get_item_value(name)
            print(f"{name} ({type}, {rarity}): {quant}x @ " +
                  f"{value} gold each = {quant * value} gold")
        except ValueError:
            print(f"ValueError: {quantity} is not number")

    def show_inventory(self, player_name: str) -> None:
        """Show the inventory of the specific player"""
        try:
            inventory = self.players['players'][player_name]
            all_items = inventory.get('items')
            item_dict = {}
            item_str = ""
            for key, value in all_items.items():
                self._display_item_in_format(key, value)
                item_type = self._get_item_type(key)
                if item_type in item_dict:
                    item_dict[item_type] += value
                else:
                    item_dict[item_type] = value
            for key, value in item_dict.items():
                item_str += f"{key}({value}), "
            print()
            print(f"Inventory value: {inventory.get('total_value')} gold")
            print(f"Item count: {inventory.get('item_count')} items")
            print(f"Categories: {item_str[0 : -2]}")
        except KeyError:
            print(f"KeyError: There is no player: '{player_name}'")

    def update_inventory(self, player: str, item: str, quantity: int,
                         operation: str) -> bool:
        """Update the item in the inventory of the specified player"""
        try:
            if player in self.players['players']:
                player_items = self.players['players'][player]
            else:
                raise KeyError(f"Error: player name {player} is wrong")
            if operation == "-":
                if item in player_items['items']:
                    if player_items['items'][item] == int(quantity):
                        self.players['players'][player]['items'].pop(item)
                    elif player_items['items'][item] > int(quantity):
                        self.players['players'][player]['items'][item] \
                            -= int(quantity)
                    else:
                        print(f"Error: {player} do not have {quantity} {item}")
                        return False
                    return True
                else:
                    raise KeyError(f"Error: {player} does not have {item}")
            elif operation == "+":
                if item in player_items['items']:
                    self.players['players'][player]['items'][item] \
                        += int(quantity)
                else:
                    self.players['players'][player]['items'][item] \
                        = int(quantity)
                return True
            else:
                print("Allowed operation are '+/-'")
                return False
        except KeyError as e:
            print(e)
        except ValueError as e:
            print(e)
        return False

    def make_transaction(self, donner: str, acceptor: str,
                         item: str, quantity: int) -> None:
        """Exchange the item between two players"""
        try:
            if donner not in self.players['players']:
                raise KeyError(f"Error: player name {donner} is wrong")
            if acceptor not in self.players['players']:
                raise KeyError(f"Error: player name {acceptor} is wrong")
        except KeyError as e:
            print(e)

        if (self.update_inventory(donner, item, quantity, "-")):
            self.update_inventory(acceptor, item, quantity, "+")
            print("Transaction successful!")

    def show_item_quantity(self, player: str, item: str) -> None:
        try:
            if player in self.players['players']:
                player_dict = self.players['players'][player]
            else:
                raise KeyError(f"Error: player name {player} is wrong")
            if item in player_dict['items']:
                print(f"{player} {item}: {player_dict['items'][item]}")
            else:
                raise KeyError(f"{player} does not have {item}")
        except KeyError as e:
            print(e)

    def show_stats(self) -> None:
        """Display the player with highest gold, and items comparing all
           players. Show the list of rarest items from the registered
           items in catalog"""
        all_players = self.players['players']
        all_catalog = self.players['catalog']
        max_gold = 0
        max_items = 0
        rare_items = ""
        for player in all_players:
            gold = all_players[player]['total_value']
            items = all_players[player]['item_count']
            if gold > max_gold:
                max_gold = gold
                valued_player = player
            if items > max_items:
                max_items = items
                item_player = player
        for item, value in all_catalog.items():
            if value['rarity'] == "rare" or\
                    value['rarity'] == "legendary":
                rare_items += f"{item}, "

        print(f"Most valuable player: {valued_player} ({max_gold} gold)")
        print(f"Most items: {item_player} ({max_items} items)")
        print(f"Rarest items: {rare_items[0: -2]}")


if __name__ == "__main__":
    data = {'players': {'alice': {'items': {'pixel_sword': 1, 'code_bow': 1, 'health_byte': 1, 'quantum_ring': 3}, 'total_value': 1875, 'item_count': 6}, 'bob': {'items': {'code_bow': 3, 'pixel_sword': 2}, 'total_value': 900, 'item_count': 5}, 'charlie': {'items': {'pixel_sword': 1, 'code_bow': 1}, 'total_value': 350, 'item_count': 2}, 'diana': {'items': {'code_bow': 3, 'pixel_sword': 3, 'health_byte': 3, 'data_crystal': 3}, 'total_value': 4125, 'item_count': 12}}, 'catalog': {'pixel_sword': {'type': 'weapon', 'value': 150, 'rarity': 'common'}, 'quantum_ring': {'type': 'accessory', 'value': 500, 'rarity': 'rare'}, 'health_byte': {'type': 'consumable', 'value': 25, 'rarity': 'common'}, 'data_crystal': {'type': 'material', 'value': 1000, 'rarity': 'legendary'}, 'code_bow': {'type': 'weapon', 'value': 200, 'rarity': 'uncommon'}}}
    players = PlayerInventoryManager(data)
    print("=== Player Inventory System ===")
    print()
    players.show_inventory("alice")
    print()
    print("=== Transaction: Alice gives Bob 2 potions ===")
    players.make_transaction("alice", "bob", "pixel_sword", 1)
    print()
    print("=== Updated Inventories ===")
    players.show_item_quantity("alice", "pixel_sword")
    players.show_item_quantity("bob", "pixel_sword")
    print()
    print("=== Inventory Analytics ===")
    players.show_stats()
