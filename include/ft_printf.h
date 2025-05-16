/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:36:59 by ygille            #+#    #+#             */
/*   Updated: 2025/05/16 14:51:40 by ygille           ###   ########.fr       */
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
	int		zeros;
	int		accuracy;
	int		left_just;
	int		right_just;
	bool	alt_form;
	bool	space;
	bool	sign;
}	t_flags;

//libftprintf.c
int		ft_printf(const char *format, ...);

//hex.c
int		hex_helper(unsigned long long val, char format, t_flags flags,
			bool suffix);

//printer_1.c
int		print_percent(int *i);
int		print_char(int *i, va_list *ap, t_flags flags);
int		print_string(int *i, va_list *ap, t_flags flags);
int		print_pointer(int *i, va_list *ap, t_flags flags);
int		print_decimal(int *i, va_list *ap, t_flags flags);

//printer_2.c
int		print_integer(int *i, va_list *ap, t_flags flags);
int		print_unsigned_decimal(int *i, va_list *ap, t_flags flags);
int		print_hex(int *i, va_list *ap, char format, t_flags flags);

//flags.c
t_flags	get_flags(const char *format, int *i);

//flags_func.c
int		ft_putstr_fd_adjust(t_flags flags, char *str, int len, int fd);
int		ft_putchar_fd_adjust(t_flags flags, char c, int fd);

#endif