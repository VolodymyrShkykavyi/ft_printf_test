/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:32:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/12/29 20:32:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static void	format_d_i_castnum(t_specinfo *info, intmax_t *num)
{
	if (info->format == 'D')
		*num = (long)(*num);
	else if (info->mod_h > 1)
		*num = (char)(*num);
	else if (info->mod_h == 1)
		*num = (short)(*num);
	else if (info->mod_l == 1)
		*num = (long)(*num);
	else if (info->mod_l > 1)
		*num = (long long)(*num);
	else if (info->mod_j)
		*num = (intmax_t)(*num);
	else if (info->mod_z)
		*num = (ssize_t)(*num);
	else
		*num = (int)(*num);
}

static void	format_d_i_printsign(t_specinfo *info, char *str)
{
	if (*str != '-' && info->plus_space == '+')
		ft_putchar('+');
	else if (*str != '-' && info->plus_space == ' ')
		ft_putchar(' ');
	else if (*str == '-')
		ft_putchar('-');
}

static void	format_d_i_printnbr(t_specinfo *info, char *str, int num_len)
{
	int		zero_len;

	zero_len = num_len - ft_strlen(str);
	if (info->plus_space && zero_len)
		zero_len--;
	if (info->precision != -1)
		format_d_i_printsign(info, str);
	ft_putnchar('0', (size_t) zero_len);
	ft_putstr((*str == '-') ? str + 1 : str);
}

void	format_d_i(t_specinfo *info, int *len, va_list *args)
{
	intmax_t	num;
	char 		*str;
	short		str_len;
	short		space_len;

	num = va_arg(*args, intmax_t);
	format_d_i_castnum(info, &num);
	str = (!num && !(info->precision)) ? ft_strnew(0) : ft_itoa_base(num, 10);
	str_len = ft_strlen(str);
	str_len = (str_len > info->precision) ? str_len : info->precision;
	if (num >= 0 && info->plus_space)
		str_len++;
	space_len =  (str_len < info->min_width) ? info->min_width - str_len : 0;
	*len += space_len + str_len;
	if (info->precision == -1)
		format_d_i_printsign(info, str);
	if (info->zero_minus != '-')
		ft_putnchar((info->zero_minus == '0' && info->precision == -1)
					? '0' : ' ', space_len);
	format_d_i_printnbr(info, str, str_len);
	if (info->zero_minus == '-')
		ft_putnchar(' ', (size_t)space_len);
	free(str);
}