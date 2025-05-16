/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:59:10 by ygille            #+#    #+#             */
/*   Updated: 2025/05/17 01:18:29 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	adjust(int just_size, int len, char c);
static int	trunc(t_flags flags, char *str, int len);

int	ft_putstr_fd_adjust(t_flags flags, char *str, int len, int fd)
{
	int	p;

	len = trunc(flags, str, len);
	if (flags.right_just || flags.left_just)
		p = adjust(flags.right_just, len, ' ');
	else
		p = adjust(flags.right_just, len, '0');
	ft_putstr_fd(str, fd);
	if (flags.left_just)
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

int	ft_putstr_fd_zero(t_flags flags, char *str, int len, int fd)
{
	int	p;

	p = 0;
	if (*str == '-')
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
	p = adjust(flags.zeros, len, '0');
	ft_putstr_fd(str, fd);
	return (p + len);
}

static int	adjust(int just_size, int len, char c)
{
	const int	diff = just_size - len;
	int			i;

	i = 0;
	if (diff > 0)
		i = diff;
	while (i)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		i--;
	}
	if (diff > 0)
		return (diff);
	return (0);
}
static int	trunc(t_flags flags, char *str, int len)
{
	if (flags.accuracy != -1 && len > flags.accuracy)
	{
		str[flags.accuracy] = '\0';
		return (flags.accuracy);
	}
	return (len);
}
