/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:59:10 by ygille            #+#    #+#             */
/*   Updated: 2025/05/16 12:47:27 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	adjust(int just_size, int len, char character);

int	ft_putstr_fd_adjust(t_flags flags, char *str, int len, int fd)
{
	int	p;

	p = adjust(flags.right_just, len, ' ');
	ft_putstr_fd(str, fd);
	p += adjust(flags.left_just, len, ' ');
	return (p + len);
}

int	ft_putchar_fd_adjust(t_flags flags, char c, int fd)
{
	int	p;

	p = adjust(flags.right_just, 1, ' ');
	ft_putchar_fd(c, fd);
	p += adjust(flags.left_just, 1, ' ');
	return (p + 1);
}

static int	adjust(int just_size, int len, char character)
{
	const int	diff = just_size - len;
	int			i;

	i = 0;
	if (diff > 0)
		i = diff;
	while (i)
	{
		ft_putchar_fd(character, STDOUT_FILENO);
		i--;
	}
	if (diff > 0)
		return (diff);
	return (0);
}
