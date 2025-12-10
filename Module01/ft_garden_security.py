# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_garden_security.py                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 22:42:14 by sudas             #+#    #+#              #
#    Updated: 2025/12/09 22:42:14 by sudas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class SecurePlant:
    def __init__(self, name: str) -> None:
        self._name = name
        self._height = None
        self._age = None
        print("Plant created:", self._name)

    def set_height(self, height: int):
        if (height >= 0):
            self._height = height
            print(f"Height updated: {height}cm [OK]")
        else:
            print(f"Invalid operation attempted: height {height}cm [REJECTED]")
            print("Security: Negative height rejected")

    def set_age(self, age: int):
        if (age >= 0):
            self._age = age
            print(f"Height updated: {age}cm [OK]")
        else:
            print(f"Invalid operation attempted: height {age}cm [REJECTED]")
            print("Security: Negative height rejected")

    def get_name(self):
        return (self._name)

    def get_height(self):
        if self._height is None:
            print(f"Height of {self._name} is not set yet!!")
        return (self._height)

    def get_age(self):
        if self._age is None:
            print(f"Age of {self._name} is not set yet!!")
        return (self._age)


if __name__ == "__main__":
    rose = SecurePlant("Rose")
    print(f"Current plant: {rose.get_name()}" +
          f"({rose.get_height()}cm, {rose.get_age()} days)")
    rose.set_age(30)
    rose.set_height(10)
    rose.set_height(-1)
    print(f"Current plant: {rose.get_name()}" +
          f"({rose.get_height()}cm, {rose.get_age()} days)")
