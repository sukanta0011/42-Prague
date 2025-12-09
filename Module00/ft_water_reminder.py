# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_water_reminder.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 13:45:41 by sudas             #+#    #+#              #
#    Updated: 2025/12/09 13:45:41 by sudas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_water_reminder():
    lst_watered = int(input("Days since last watering: "))
    if (lst_watered > 2):
        print("Water the plants!")
    else:
        print("Plants are fine.")
