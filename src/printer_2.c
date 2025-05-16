/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:34:33 by ygille            #+#    #+#             */
/*   Updated: 2025/05/16 14:48:20 by ygille           ###   ########.fr       */
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
	p = ft_putstr_fd_adjust(flags, num, ft_strlen(num), STDOUT_FILENO);
	free(num);
	return (p);
}

int	print_hex(int *i, va_list *ap, char format, t_flags flags)
{
	int	p;

	(*i)++;
	p = hex_helper(va_arg(*ap, unsigned int), format, flags, false);
	return (p);
}
