/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:39:08 by sudas             #+#    #+#             */
/*   Updated: 2026/05/17 23:52:36 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	parent(int index)
{
	return ((index - 1) / 2);
}

int	left_child(int index)
{
	return (2 * index + 1);
}

int	right_child(int index)
{
	return (2 * index + 2);
}
