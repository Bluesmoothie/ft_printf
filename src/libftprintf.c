/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:42:13 by ygille            #+#    #+#             */
/*   Updated: 2024/11/15 12:52:29 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

static	int	handle_percent(const char *format, va_list *ap, int *i);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			j++;
			i++;
		}
		else
			j += handle_percent(format, &ap, &i);
	}
	va_end(ap);
	return (j);
}

static int	handle_percent(const char *format, va_list *ap, int *i)
{
	(*i) += 1;
	if (format[*i] == '%')
		return (print_percent(i));
	else if (format[*i] == 'c')
		return (print_char(i, ap));
	else if (format[*i] == 's')
		return (print_string(i, ap));
	return (0);
}

int	main(int argc, char *argv[])
{
	return (ft_printf(argv[1], argv[2]));
}
