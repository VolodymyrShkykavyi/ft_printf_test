/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 01:11:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/12/23 01:11:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_manager(t_specinfo *info, int *len, va_list *args)
{
	if (info->format == 's' || info->format == 'S')
		format_s(info, len, args);
	else if (info->format == 'c' || info->format == 'C')
		format_c(info, len, args);
	else if (info->format == 'd' || info->format == 'D' || info->format == 'i')
		format_d_i(info, len, args);
	else if (info->format == 'n')
		format_n(info, len, args);
	else if (info->format == 'o' || info->format == 'O')
		format_o(info, len, args);
	else
		va_arg(*args, int);
}