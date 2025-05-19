/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:59:10 by ygille            #+#    #+#             */
/*   Updated: 2025/05/19 12:05:55 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	adjust(int just_size, int len, char c, int fd);
static int	trunc(t_flags flags, char **str, int len);

int	ft_putstr_fd_adjust(t_flags flags, char *str, int len, int fd)
{
	int	p;
	int	i;

	p = 0;
	i = 0;
	len = trunc(flags, &str, len);
	if (!str)
		return (0);
	if (flags.right_just || flags.left_just)
		p += adjust(flags.right_just, len, ' ', fd);
	else if (is_numeric(flags.format))
	{
		if (*str == '-')
		{
			ft_putchar_fd(str[i++], fd);
			p++;
			len--;
		}
		if (flags.zeros && *str == '-')
			p += adjust(flags.zeros, len + 1, '0', fd);
		else if (flags.zeros)
			p += adjust(flags.zeros, len, '0', fd);
		else if (flags.accuracy > len)
			p += adjust(flags.accuracy, len, '0', fd);
	}
	ft_putstr_fd(&str[i], fd);
	if (flags.left_just)
		p += adjust(flags.left_just, len, ' ', fd);
	free(str);
	return (p + len);
}

int	ft_putchar_fd_adjust(t_flags flags, char c, int fd)
{
	int	p;

	p = adjust(flags.right_just, 1, ' ', fd);
	ft_putchar_fd(c, fd);
	p += adjust(flags.left_just, 1, ' ', fd);
	return (p + 1);
}

static int	adjust(int just_size, int len, char c, int fd)
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

static int	trunc(t_flags flags, char **str, int len)
{
	if (!is_numeric(flags.format)
		&& flags.accuracy != -1 && len > flags.accuracy)
	{
		*str = ft_substr(*str, 0, flags.accuracy);
		return (flags.accuracy);
	}
	*str = ft_strdup(*str);
	return (len);
}
