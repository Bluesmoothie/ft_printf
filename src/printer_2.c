/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:34:33 by ygille            #+#    #+#             */
/*   Updated: 2025/05/19 12:31:57 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(int *i, va_list *ap, t_flags flags)
{
	return (print_decimal(i, ap, flags));
}

int	print_unsigned_decimal(int *i, va_list *ap, t_flags flags)
{
	char	*num;
	int		p;

	(*i)++;
	num = ft_uitoa(va_arg(*ap, unsigned int));
	p = ft_putstr_fd_adjust(flags, num, ft_strlen(num), flags.fd);
	free(num);
	return (p);
}

int	print_hex(int *i, va_list *ap, char format, t_flags flags)
{
	int		p;
	char	*num;

	(*i)++;
	num = hex_helper(va_arg(*ap, unsigned int), format, flags.alt_form);
	if (!num)
		return (0);
	p = ft_putstr_fd_adjust(flags, num, ft_strlen(num), flags.fd);
	free(num);
	return (p);
}

int	sign_flags(t_flags flags, char *str, int fd)
{
	char	c;

	c = 0;
	if (flags.sign)
		c = '+';
	else if (flags.space)
		c = ' ';
	if (c && *str != '-')
	{
		ft_putchar_fd(c, fd);
		return (1);
	}
	return (0);
}
