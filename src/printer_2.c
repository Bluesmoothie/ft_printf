/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:34:33 by ygille            #+#    #+#             */
/*   Updated: 2025/05/16 21:16:04 by ygille           ###   ########.fr       */
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
	if (flags.left_just || flags.right_just)
		p = ft_putstr_fd_adjust(flags, num, ft_strlen(num), STDOUT_FILENO);
	else
		p = ft_putstr_fd_zero(flags, num, ft_strlen(num), STDOUT_FILENO);
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
	if (flags.left_just || flags.right_just)
		p = ft_putstr_fd_adjust(flags, num, ft_strlen(num), STDOUT_FILENO);
	else
		p = ft_putstr_fd_zero(flags, num, ft_strlen(num), STDOUT_FILENO);
	free(num);
	return (p);
}
