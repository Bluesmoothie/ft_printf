/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:11:31 by ygille            #+#    #+#             */
/*   Updated: 2025/05/16 13:30:19 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	hex(unsigned long long val, char format);

int	hex_helper(unsigned long long val, char format, t_flags flags, bool suffix)
{
	int		i;
	char	ptr[19];

	i = 18;
	ptr[i] = '\0';
	if (!val)
		ptr[--i] = '0';
	while (val)
	{
		i--;
		ptr[i] = hex(val, format);
		val /= 16;
	}
	if (suffix)
	{
		ptr[--i] = 'x';
		ptr[--i] = '0';
	}
	return (ft_putstr_fd_adjust(flags, &ptr[i], 18 - i, STDOUT_FILENO));
}

static char	hex(unsigned long long val, char format)
{
	if (format == UP)
		return (UP_BASE_HEX[val % 16]);
	return (LOW_BASE_HEX[val % 16]);
}
