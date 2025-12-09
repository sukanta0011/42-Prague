# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_harvest_total.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 13:37:58 by sudas             #+#    #+#              #
#    Updated: 2025/12/09 13:37:58 by sudas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_harvest_total():
    day1_hrvst = int(input("Day 1 harvest: "))
    day2_hrvst = int(input("Day 2 harvest: "))
    day3_hrvst = int(input("Day 3 harvest: "))
    total_hrvst = day1_hrvst + day2_hrvst + day3_hrvst
    print("Total harvest:", total_hrvst)
