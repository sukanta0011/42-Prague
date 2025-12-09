# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_garden_data.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 15:20:21 by sudas             #+#    #+#              #
#    Updated: 2025/12/09 15:20:21 by sudas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self._name = name
        self._height = height
        self._age = age

    def get_info(self):
        print(f"{self._name}: {self._height}cm, {self._age} days old")

    def grow(self, new_height: int):
        self._height = new_height

    def age(self, new_age: int):
        self._age = new_age


def my_plants():
    print("=== Day 1 ===")
    initial_height = 25
    rose = Plant("Rose", initial_height, 30)
    rose.get_info()
    print("=== Day 7 ===")
    final_height = 31
    rose.age(36)
    rose.grow(final_height)
    rose.get_info()
    print(f"Growth this week: +{final_height - initial_height}cm")


if __name__ == "__main__":
    my_plants()
