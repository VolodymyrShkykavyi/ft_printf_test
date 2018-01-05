/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:34:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/05 13:34:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_toupper(char **str)
{
	size_t	i;

	i = 0;
	while ((*str)[i])
	{
		(*str)[i] = ft_toupper((*str)[i]);
		i++;
	}
}