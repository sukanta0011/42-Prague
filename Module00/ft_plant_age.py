# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_plant_age.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 13:41:58 by sudas             #+#    #+#              #
#    Updated: 2025/12/09 13:41:58 by sudas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_plant_age():
    plant_age = int(input("Enter plant age in days: "))
    if (plant_age > 60):
        print("Plant is ready to harvest!")
    else:
        print("Plant needs more time to grow.")