/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:31:00 by ygille            #+#    #+#             */
/*   Updated: 2025/05/13 16:52:25 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool		flags_present(char format);
static size_t	flag_value(char *format, int *i);

t_flags	get_flags(char *format, int *i)
{
	t_flags	flags;

	(*i)++;
	ft_bzero(&flags, sizeof(t_flags));
	while (flags_present(format[*i]))
	{
		if (format[*i] == '#')
			flags.alt_form = true;
		else if (format[*i] == ' ')
			flags.space = true;
		else if (format[*i] == '+')
			flags.sign = true;
		else if (format[*i] == '-')
			flags.left_just = true;
		else if (format[*i] == '0')
			flags.zeros = flag_value(format, i);
		else if (format[*i] == '.')
			flags.accuracy = flag_value(format, i);
		(*i)++;
	}
}

static bool	flags_present(char format)
{
	return (format == '#' || format == ' ' || format == '+' || format == '-'
			|| format == '0' || format == '.');
}

static size_t	flag_value(char *format, int *i)
{
	const size_t	val = ft_atoi(&format[*i + 1]);

	while (format[*i] && ft_isdigit(format[*i]))
		(*i)++;
	return (val);
}
