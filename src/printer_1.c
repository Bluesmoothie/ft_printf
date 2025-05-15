/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:38 by ygille            #+#    #+#             */
/*   Updated: 2025/05/15 16:19:26 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(int *i)
{
	(*i) += 1;
	ft_putchar_fd('%', STDOUT_FILENO);
	return (1);
}

int	print_char(int *i, va_list *ap, t_flags flags)
{
	int	p;

	(*i) += 1;
	p = adjust(flags.right_just, 1, ' ');
	ft_putchar_fd(va_arg(*ap, int), STDOUT_FILENO);
	p += adjust(flags.left_just, 1, ' ');
	return (1 + p);
}

int	print_string(int *i, va_list *ap, t_flags flags)
{
	char	*s;
	int		p;
	int		len;

	(*i) += 1;
	s = va_arg(*ap, char *);
	len = 6;
	if (s == NULL)
	{
		p = adjust(flags.right_just, len, ' ');
		ft_putstr_fd("(null)", STDOUT_FILENO);
		p += adjust(flags.left_just, len, ' ');
	}
	else
	{
		len = ft_strlen(s);
		p = adjust(flags.right_just, len, ' ');
		ft_putstr_fd(s, STDOUT_FILENO);
		p += adjust(flags.left_just, len, ' ');
	}
	return (len + p);
}

int	print_pointer(int *i, va_list *ap)
{
	int					j;
	unsigned long long	val;

	(*i) += 1;
	val = va_arg(*ap, unsigned long long);
	j = 0;
	if (val == 0)
	{
		j += 5;
		ft_putstr_fd("(nil)", STDOUT_FILENO);
	}
	else
	{
		j += 2;
		ft_putstr_fd("0x", STDOUT_FILENO);
		hex(val, LOW, &j);
	}
	return (j);
}

int	print_decimal(int *i, va_list *ap)
{
	char	*num;
	int		size;

	(*i) += 1;
	num = ft_itoa(va_arg(*ap, int));
	ft_putstr_fd(num, STDOUT_FILENO);
	size = ft_strlen(num);
	free(num);
	return (size);
}
