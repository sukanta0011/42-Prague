# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_plant_types.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/10 08:46:20 by sudas             #+#    #+#              #
#    Updated: 2025/12/10 08:46:20 by sudas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self._name = name
        self._height = height
        self._age = age

    def get_name(self):
        return (self._name)

    def get_height(self):
        return (self._height)

    def get_age(self):
        return (self._age)


class Flower(Plant):
    def __init__(self, name: str, height: int, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self._color = color

    def get_color(self):
        return (self._color)

    def bloom(self):
        print(f"{self.get_name()} is blooming beautifully!")


class Tree(Plant):
    def __init__(self, name: str, height: int, age: int,
                 trunk_diameter: int) -> None:
        super().__init__(name, height, age)
        self._trunk_diameter = trunk_diameter

    def get_trunk_diameter(self):
        return (self._trunk_diameter)

    def produce_shade(self):
        print(f"{self.get_name()} provides {self.get_trunk_diameter()}\
              square meters of shade")


class Vegetable(Plant):
    def __init__(self, name: str, height: int, age: int,
                 harvest_season: str, nutritional_value: str) -> None:
        super().__init__(name, height, age)
        self._harvest_season = harvest_season
        self._nutritional_value = nutritional_value

    def get_harvest_season(self):
        return (self._harvest_season)

    def get_nutritional_value(self):
        return (self._nutritional_value)

if __name__ == "__main__":
    rose = Flower("Rose", 25, 30, "red color")
    