/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:38 by ygille            #+#    #+#             */
/*   Updated: 2025/05/17 01:06:48 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(int *i)
{
	(*i)++;
	ft_putchar_fd('%', STDOUT_FILENO);
	return (1);
}

int	print_char(int *i, va_list *ap, t_flags flags)
{
	int		p;

	(*i)++;
	p = ft_putchar_fd_adjust(flags, va_arg(*ap, int), STDOUT_FILENO);
	return (p);
}

int	print_string(int *i, va_list *ap, t_flags flags)
{
	char	*s;
	int		p;

	(*i)++;
	s = va_arg(*ap, char *);
	p = 0;
	if (s == NULL)
		p = ft_putstr_fd_adjust(flags, "(null)", 6, STDOUT_FILENO);
	else
		p = ft_putstr_fd_adjust(flags, s, ft_strlen(s), STDOUT_FILENO);
	return (p);
}

int	print_pointer(int *i, va_list *ap, t_flags flags)
{
	int					p;
	unsigned long long	val;
	char				*num;

	(*i)++;
	val = va_arg(*ap, unsigned long long);
	if (val == 0)
		p = ft_putstr_fd_adjust(flags, "(nil)", 5, STDOUT_FILENO);
	else
	{
		num = hex_helper(val, LOW, true);
		if (!num)
			return (0);
		p = ft_putstr_fd_adjust(flags, num, ft_strlen(num), STDOUT_FILENO);
		free(num);
	}
	return (p);
}

int	print_decimal(int *i, va_list *ap, t_flags flags)
{
	int		len;
	int		p;
	char	*num;

	(*i)++;
	num = ft_itoa(va_arg(*ap, int));
	len = ft_strlen(num);
	len += sign_flags(flags, num, STDOUT_FILENO);
	p = ft_putstr_fd_adjust(flags, num, len, STDOUT_FILENO);
	free(num);
	return (p);
}
