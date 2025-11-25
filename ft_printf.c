/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:55:09 by sudas             #+#    #+#             */
/*   Updated: 2025/09/11 09:55:09 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt_specifier	*initialize_mem(t_fmt_specifier *fmt_spcfr)
{
	fmt_spcfr = malloc(sizeof(t_fmt_specifier));
	fmt_spcfr->flag_dtls.str = NULL;
	fmt_spcfr->flag_dtls.len = 0;
	fmt_spcfr->flag_dtls.size = 2;
	fmt_spcfr->flags = 0;
	fmt_spcfr->flag_len = 0;
	fmt_spcfr->dot = 0;
	fmt_spcfr->width = 0;
	fmt_spcfr->precision = 0;
	fmt_spcfr->specifier = 0;
	fmt_spcfr->var.str = NULL;
	fmt_spcfr->var.len = 0;
	fmt_spcfr->var.size = 2;
	return (fmt_spcfr);
}

void	free_memory(t_fmt_specifier *fmt_spcfr)
{
	if (fmt_spcfr->flag_dtls.str)
		free(fmt_spcfr->flag_dtls.str);
	if (fmt_spcfr->var.str)
		free(fmt_spcfr->var.str);
	free(fmt_spcfr);
}

void	modify_len(t_uint *len, t_fmt_specifier *fmt_spcfr)
{
	if (fmt_spcfr->specifier == 's' || fmt_spcfr->specifier == 'c')
	{
		if (fmt_spcfr->dot)
		{
			if (fmt_spcfr->width >= get_min_len(fmt_spcfr->precision,
					fmt_spcfr->var.len))
				(*len) += fmt_spcfr->width;
			else if (fmt_spcfr->precision > fmt_spcfr->var.len)
				(*len) += fmt_spcfr->var.len;
			else
				(*len) += fmt_spcfr->precision;
		}
		else
			(*len) += get_max_len(fmt_spcfr->width,
					fmt_spcfr->precision, fmt_spcfr->var.len);
	}
	else
	{
		(*len) += fmt_spcfr->flag_len;
		(*len) += get_max_len(fmt_spcfr->width,
				fmt_spcfr->precision, fmt_spcfr->var.len);
	}
}

void	extract_args(int *i, t_fmt_specifier *fmt_spcfr, char *fmt, va_list ap)
{
	*i++;
	fmt_spcfr = initialize_mem(fmt_spcfr);
	parse_specifier(fmt_spcfr, (char *)fmt, i);
	parse_specifier_value(fmt_spcfr, ap);
}

int	ft_printf(const char *fmt, ...)
{
	va_list			ap;
	t_fmt_specifier	*fmt_spcfr;
	t_uint			i;
	t_uint			len;

	i = 0;
	len = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			// i++;
			// fmt_spcfr = initialize_mem(fmt_spcfr);
			// parse_specifier(fmt_spcfr, (char *)fmt, &i);
			// parse_specifier_value(fmt_spcfr, ap);
			// modify_len(&len, fmt_spcfr);
			// free_memory(fmt_spcfr);
			extract_args(&i, fmt_spcfr, (char *)fmt, ap);
			modify_len(&len, fmt_spcfr);
			free_memory(fmt_spcfr);
		}
		else
		{
			ft_putchar(fmt[i]);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
