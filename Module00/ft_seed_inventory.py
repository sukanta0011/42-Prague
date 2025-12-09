# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_seed_inventory.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 14:34:45 by sudas             #+#    #+#              #
#    Updated: 2025/12/09 14:34:45 by sudas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    if (unit == "packets"):
        print(f"{seed_type.title()} seeds: {quantity} packets available")
    elif (unit == "grams"):
        print(f"{seed_type.title()} seeds: {quantity} grams total")
    elif (unit == "area"):
        print(f"{seed_type.title()} seeds: covers {quantity} square meters")
    else:
        print("Unknown unit type")
