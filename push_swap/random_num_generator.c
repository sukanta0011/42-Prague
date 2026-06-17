/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_num_generator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:50:08 by sudas             #+#    #+#             */
/*   Updated: 2025/09/29 13:50:08 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	print_randoms(int min, int max, int count)
{
	int	rd_num;
	int	i;

	i = 0;
	while (i < count)
	{
		rd_num = rand() % (max - min + 1) + min;
		printf("%d ", rd_num);
		i++;
	}
}

int	main(void)
{
	int	min;
	int	max;
	int	count;

	min = -1000;
	max = 1000;
	count = 100;
	print_randoms(min, max, count);
	printf("\n");
	return (0);
}
