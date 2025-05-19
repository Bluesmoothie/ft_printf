/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:29:23 by ygille            #+#    #+#             */
/*   Updated: 2025/05/19 16:42:13 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_putstr_fd_adjust_alpha(t_flags flags, char *str,
					int len, int fd);
static int		ft_putstr_fd_adjust_numeric(t_flags flags, char *str,
					int len, int fd);

int	ft_putstr_fd_adjust(t_flags flags, char *str, int len, int fd)
{
	if (is_numeric(flags.format))
		return (ft_putstr_fd_adjust_numeric(flags, str, len, fd));
	return (ft_putstr_fd_adjust_alpha(flags, str, len, fd));
}

static int	ft_putstr_fd_adjust_alpha(t_flags flags, char *str, int len, int fd)
{
	int	p;
	int	i;

	p = 0;
	i = 0;
	len = ft_trunc(flags, &str, len);
	if (!str)
		return (0);
	if (flags.right_just)
		p += adjust(flags.right_just, len, ' ', fd);
	ft_putstr_fd(&str[i], fd);
	if (flags.left_just)
		p += adjust(flags.left_just, len, ' ', fd);
	free(str);
	return (p + len);
}

static int	ft_putstr_fd_adjust_numeric(t_flags flags, char *str,
		int len, int fd)
{
	int		p;
	bool	sign;

	p = 0;
	sign = false;
	if (flags.right_just)
		p += adjust(flags.right_just, len, ' ', fd);
	if (flags.accuracy != -1 && flags.accuracy - len < flags.zeros)
		p += adjust(flags.zeros - flags.accuracy + len, len, ' ', fd);
	if (*str == '-')
	{
		ft_putchar_fd(*str, fd);
		str++;
		sign = true;
	}
	if (!flags.right_just && flags.accuracy == -1)
		p += adjust(flags.zeros, len, '0', fd);
	else if (flags.accuracy != -1)
		p += adjust(flags.accuracy, len - sign, '0', fd);
	ft_putstr_fd(str, fd);
	if (flags.left_just)
		p += adjust(flags.left_just, len + p, ' ', fd);
	return (p + len);
}
