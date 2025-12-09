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

    def name(self):
        return (self._name)

    def height(self):
        return (self._height)

    def age(self):
        return (self._age)


def my_plants():
    rose = Plant("Rose", 25, 30)
    sn_flwr = Plant("Sunflower", 80, 45)
    cactus = Plant("Cactus", 15, 120)
    print("=== Garden Plant Registry ===")
    print(f"{rose.name()}: {rose.height()}cm, {rose.age()} days old")
    print(f"{sn_flwr.name()}: {sn_flwr.height()}cm, {sn_flwr.age()} days old")
    print(f"{cactus.name()}: {cactus.height()}cm, {cactus.age()} days old")


if __name__ == "__main__":
    my_plants()
