# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_count_harvest_iterative.py                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 13:49:18 by sudas             #+#    #+#              #
#    Updated: 2025/12/09 13:49:18 by sudas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_count_harvest_iterative():
    until_hrvst = int(input("Days until harvest: "))
    for i in range(1, until_hrvst + 1):
        print("Day", i)
    print("Harvest time!")
