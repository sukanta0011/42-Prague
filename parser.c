/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:38:55 by sudas             #+#    #+#             */
/*   Updated: 2026/05/17 02:56:22 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_config	*extract_config()
{
    t_config *config;

    config = malloc(sizeof(t_config));

    config->number_of_coders = 1;
    config->time_to_burnout = 849;
    config->time_to_compile = 200;
    config->time_to_debug = 200;
    config->time_to_refactor = 200;
    config->number_of_compiles_required = 5;
    config->dongle_cooldown = 50;
    config->scheduler_type = "EDF";

    return config;
}