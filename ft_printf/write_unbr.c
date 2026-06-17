/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nbr1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:55:22 by sudas             #+#    #+#             */
/*   Updated: 2025/09/11 09:55:22 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_base(t_fmt_specifier *fmt_spcfr, t_uint nbr,
		char *base, t_uint base_len)
{
	int		mod;

	if (nbr > base_len - 1)
		ft_putunbr_base(fmt_spcfr, nbr / base_len, base, base_len);
	mod = nbr % base_len;
	append_char(&(fmt_spcfr->var), base[mod]);
}

void	print_unum_with_paddings(t_fmt_specifier *fmt_spcfr, char *hx_str)
{
	if (fmt_spcfr->flags)
	{
		if (char_in_str('#', fmt_spcfr->flag_dtls.str)
			&& ft_strncmp(fmt_spcfr->var.str, "0", fmt_spcfr->var.len))
		{
			if (fmt_spcfr->specifier == 'x')
				hx_str = "0x";
			if (fmt_spcfr->specifier == 'X')
				hx_str = "0X";
			fmt_spcfr->width -= 2;
			fmt_spcfr->flag_len += 2;
		}
		if (char_in_str('-', fmt_spcfr->flag_dtls.str))
			use_num_right_padding(fmt_spcfr, ' ', hx_str);
		else if (char_in_str('0', fmt_spcfr->flag_dtls.str) && !fmt_spcfr->dot)
			use_num_left_padding(fmt_spcfr, '0', hx_str);
		else if (char_in_str('0', fmt_spcfr->flag_dtls.str) && fmt_spcfr->dot)
			use_num_left_padding(fmt_spcfr, ' ', hx_str);
		else if (char_in_str('#', fmt_spcfr->flag_dtls.str))
			use_num_left_padding(fmt_spcfr, ' ', hx_str);
		else
			use_num_left_padding(fmt_spcfr, ' ', hx_str);
	}
	else
		use_num_left_padding(fmt_spcfr, ' ', hx_str);
}

void	print_unbr(t_fmt_specifier *fmt_spcfr, t_uint num, char fmt)
{
	char	*cap_hex_base;
	char	*hex_base;
	char	*dec_base;
	char	*hx_str;

	hx_str = "";
	cap_hex_base = "0123456789ABCDEF";
	hex_base = "0123456789abcdef";
	dec_base = "0123456789";
	if (fmt == 'u')
		ft_putunbr_base(fmt_spcfr, num, dec_base, DEC_LEN);
	if (fmt == 'x')
		ft_putunbr_base(fmt_spcfr, num, hex_base, HEX_LEN);
	if (fmt == 'X')
		ft_putunbr_base(fmt_spcfr, num, cap_hex_base, HEX_LEN);
	print_unum_with_paddings(fmt_spcfr, hx_str);
}
