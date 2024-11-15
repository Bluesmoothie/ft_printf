/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:49:38 by ygille            #+#    #+#             */
/*   Updated: 2024/11/15 12:54:05 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

int	print_percent(int *i)
{
	ft_putchar_fd('%', 1);
	(*i) += 1;
	return (1);
}

int	print_char(int *i, va_list *ap)
{
	ft_putchar_fd(*(va_arg(*ap, char *)), 1);
	(*i) += 1;
	return (1);
}

int	print_string(int *i, va_list *ap)
{
	char	*s;

	s = va_arg(*ap, char *);
	ft_putstr_fd(s, 1);
	(*i) += 1;
	return (ft_strlen(s));
}
