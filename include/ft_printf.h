/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:36:59 by ygille            #+#    #+#             */
/*   Updated: 2025/05/13 16:35:14 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define LOW_BASE_HEX	"0123456789abcdef"
# define UP_BASE_HEX	"0123456789ABCDEF"
# define UP				'X'
# define LOW			'x'

# include <libft.h>
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_flags
{
	size_t	zeros;
	size_t	accuracy;
	bool	left_just;
	bool	alt_form;
	bool	space;
	bool	sign;
}	t_flags;


//libftprintf.c
int		ft_printf(const char *format, ...);

//hex.c
void	hex(unsigned long long val, char format, int *i);

//printer_1.c
int		print_percent(int *i);
int		print_char(int *i, va_list *ap);
int		print_string(int *i, va_list *ap);
int		print_pointer(int *i, va_list *ap);
int		print_decimal(int *i, va_list *ap);

//printer_2.c
int		print_integer(int *i, va_list *ap);
int		print_unsigned_decimal(int *i, va_list *ap);
int		print_hex(int *i, va_list *ap, char format);

//flags.c
t_flags	get_flags(char *format, int *i);

#endif