/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:13:21 by sudas             #+#    #+#             */
/*   Updated: 2025/11/24 11:13:21 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_signed_num(t_fmt_specifier *fmt_spcfr, t_fmt *var, va_list ap)
{
	var->num = va_arg(ap, int);
	if (fmt_spcfr->dot && var->num == 0
		&& fmt_spcfr->precision == 0)
	{
		if (fmt_spcfr->flag_dtls.str
			&& char_in_str('0', fmt_spcfr->flag_dtls.str))
			use_num_right_padding(fmt_spcfr, ' ', "");
		else
			print_str(fmt_spcfr, "");
	}
	else
		print_nbr(fmt_spcfr, var->num);
}

void	parse_unsigned_num(t_fmt_specifier *fmt_spcfr, t_fmt *var, va_list ap)
{
	var->unum = va_arg(ap, t_uint);
	if (fmt_spcfr->dot && var->unum == 0
		&& fmt_spcfr->precision == 0)
	{
		if (fmt_spcfr->flag_dtls.str
			&& char_in_str('0', fmt_spcfr->flag_dtls.str))
			use_num_right_padding(fmt_spcfr, ' ', "");
		else
			print_str(fmt_spcfr, "");
	}
	else
	{
		print_unbr(fmt_spcfr, var->unum, fmt_spcfr->specifier);
		if ((fmt_spcfr->specifier == 'x' || fmt_spcfr->specifier == 'X')
			&& fmt_spcfr->precision == 0)
			fmt_spcfr->precision += fmt_spcfr->var.len;
	}
}

void	parse_str(t_fmt_specifier *fmt_spcfr, t_fmt *var, char fmt, va_list ap)
{
	if (fmt == 's')
	{
		var->str = va_arg(ap, char *);
		if (var->str == NULL)
		{
			var->str = "(null)";
			if (fmt_spcfr->precision < NULL_LEN)
				fmt_spcfr->precision = 0;
		}
		print_str(fmt_spcfr, var->str);
	}
	if (fmt == 'c')
	{
		var->num = va_arg(ap, int);
		print_char(fmt_spcfr, var->num);
	}
}

void	parse_ptr(t_fmt_specifier *fmt_spcfr, t_fmt *var, va_list ap)
{
	var->ptr = va_arg(ap, void *);
	if (var->ptr != NULL)
		print_ptr(fmt_spcfr, var->ptr);
	else
	{
		var->str = "(nil)";
		print_str(fmt_spcfr, var->str);
	}
}
