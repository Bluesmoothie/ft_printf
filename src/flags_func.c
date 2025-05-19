/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:59:10 by ygille            #+#    #+#             */
/*   Updated: 2025/05/19 13:13:00 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd_adjust(t_flags flags, char c, int fd)
{
	int	p;

	p = adjust(flags.right_just, 1, ' ', fd);
	ft_putchar_fd(c, fd);
	p += adjust(flags.left_just, 1, ' ', fd);
	return (p + 1);
}

int	adjust(int just_size, int len, char c, int fd)
{
	const int	diff = just_size - len;
	int			i;

	i = 0;
	if (diff > 0)
		i = diff;
	while (i)
	{
		ft_putchar_fd(c, fd);
		i--;
	}
	if (diff > 0)
		return (diff);
	return (0);
}

int	ft_trunc(t_flags flags, char **str, int len)
{
	if (flags.null && flags.accuracy != -1 && flags.accuracy < len)
	{
		*str = NULL;
		return (0);
	}
	if (flags.accuracy != -1 && len > flags.accuracy)
	{
		*str = ft_substr(*str, 0, flags.accuracy);
		return (flags.accuracy);
	}
	*str = ft_strdup(*str);
	return (len);
}
