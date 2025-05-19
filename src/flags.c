/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:31:00 by ygille            #+#    #+#             */
/*   Updated: 2025/05/19 17:16:42 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool		flags_present(const char format);
static size_t	flag_value(const char *format, int *i);
static char		*extract_value(const char *format, int *i);

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
	flags.format = format[*i];
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
	char	*str_val;

	if (format[*i] == '0')
	{
		(*i)++;
		str_val = extract_value(format, i);
		val = ft_atoi(str_val);
		free(str_val);
		(*i)--;
		return (val);
	}
	if (!ft_isdigit(format[*i]))
		(*i)++;
	val = ft_atoi(&format[(*i)]);
	while (format[*i] && ft_isdigit(format[*i]))
		(*i)++;
	(*i)--;
	return (val);
}

bool	is_numeric(char f)
{
	return (f == 'd' || f == 'i' || f == 'u' || f == 'x' || f == 'X');
}

static char	*extract_value(const char *format, int *i)
{
	int		start;
	char	*r;

	start = *i;
	if (format[*i] == '0')
	{
		r = ft_substr(format, start, (*i) - 1);
		(*i)++;
		return (r);
	}
	while (format[*i] && ft_isdigit(format[*i]))
		(*i)++;
	return (ft_substr(format, start, (*i) - start));
}
