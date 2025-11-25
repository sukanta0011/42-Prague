/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:26:09 by sudas             #+#    #+#             */
/*   Updated: 2025/11/24 11:26:09 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(t_fmt_specifier *fmt_spcfr, int nbr,
		char *base, t_uint base_len)
{
	int		mod;
	t_uint	new_nb;

	if (nbr < 0)
		new_nb = -nbr;
	else
		new_nb = nbr;
	if (new_nb > base_len - 1)
		ft_putnbr_base(fmt_spcfr, new_nb / base_len, base, base_len);
	mod = new_nb % base_len;
	append_char(&(fmt_spcfr->var), base[mod]);
}

void	handle_nbr_flags(t_fmt_specifier *fmt_spcfr, int num)
{
	char	*sign_str;

	sign_str = "";
	if (char_in_str(' ', fmt_spcfr->flag_dtls.str))
		sign_str = " ";
	if (num < 0)
		sign_str = "-";
	if (char_in_str('+', fmt_spcfr->flag_dtls.str) && num >= 0)
		sign_str = "+";
	if (num < 0 || char_in_str('+', fmt_spcfr->flag_dtls.str)
		|| char_in_str(' ', fmt_spcfr->flag_dtls.str))
	{
		fmt_spcfr->width -= 1;
		fmt_spcfr->flag_len += 1;
	}
	if (char_in_str('-', fmt_spcfr->flag_dtls.str))
		use_num_right_padding(fmt_spcfr, ' ', sign_str);
	else if (char_in_str('0', fmt_spcfr->flag_dtls.str) && !fmt_spcfr->dot)
		use_num_left_padding(fmt_spcfr, '0', sign_str);
	else if (char_in_str('0', fmt_spcfr->flag_dtls.str) && fmt_spcfr->dot)
		use_num_left_padding(fmt_spcfr, ' ', sign_str);
	else if (char_in_str('+', fmt_spcfr->flag_dtls.str)
		|| char_in_str(' ', fmt_spcfr->flag_dtls.str))
		use_num_left_padding(fmt_spcfr, ' ', sign_str);
}

void	print_nbr(t_fmt_specifier *fmt_spcfr, int num)
{
	char	*sign_str;

	sign_str = "";
	if (num < 0)
		sign_str = "-";
	ft_putnbr_base(fmt_spcfr, num, "0123456789", DEC_LEN);
	if (num < 0 && !fmt_spcfr->flags)
	{
		fmt_spcfr->width -= 1;
		fmt_spcfr->flag_len += 1;
	}
	if (fmt_spcfr->flags)
		handle_nbr_flags(fmt_spcfr, num);
	else
		use_num_left_padding(fmt_spcfr, ' ', sign_str);
}
