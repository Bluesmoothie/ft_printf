/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:31:00 by ygille            #+#    #+#             */
/*   Updated: 2025/05/16 23:22:12 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool		flags_present(const char format);
static size_t	flag_value(const char *format, int *i);

t_flags	get_flags(const char *format, int *i)
{
	t_flags	flags;

	(*i)++;
	ft_bzero(&flags, sizeof(t_flags));
	flags.accuracy = -1;
	while (flags_present(format[*i]))
	{
		if (format[*i] == '#')
			flags.alt_form = true;
		else if (format[*i] == ' ')
			flags.space = true;
		else if (format[*i] == '+')
			flags.sign = true;
		else if (format[*i] == '-')
			flags.left_just = flag_value(format, i);
		else if (format[*i] == '0')
			flags.zeros = flag_value(format, i);
		else if (format[*i] == '.')
			flags.accuracy = flag_value(format, i);
		else if (ft_isdigit(format[*i]))
			flags.right_just = flag_value(format, i);
		(*i)++;
	}
	return (flags);
}

static bool	flags_present(const char format)
{
	return (format == '#' || format == ' ' || format == '+' || format == '-'
		|| format == '0' || format == '.' || ft_isdigit(format));
}

static size_t	flag_value(const char *format, int *i)
{
	size_t	val;

	if (!ft_isdigit(format[*i]))
		(*i)++;
	val = ft_atoi(&format[(*i)]);
	while (format[*i] && ft_isdigit(format[*i]))
		(*i)++;
	(*i)--;
	return (val);
}

int	ft_putstr_fd_trunc(char *str, int fd, t_flags flags, int len)
{
	int	p;

	if (flags.accuracy != -1 && len > flags.accuracy)
	{
		write(fd, str, flags.accuracy);
		p = flags.accuracy;
	}
	else
	{
		ft_putstr_fd(str, fd);
		p = len;
	}
	while (flags.right_just > p)
	{
		ft_putchar_fd(' ', fd);
		flags.left_just--;
	}
	return (p);
}
