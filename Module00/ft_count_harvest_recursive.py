# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_count_harvest_recursive.py                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 14:03:34 by sudas             #+#    #+#              #
#    Updated: 2025/12/09 14:03:34 by sudas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_print_recursive(day: int):
    if (day > 1):
        ft_print_recursive(day - 1)
    print("Day", day)


def ft_count_harvest_recursive():
    until_hrvst = int(input("Days until harvest: "))
    ft_print_recursive(until_hrvst)
    print("Harvest time!")
