/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:29:23 by ygille            #+#    #+#             */
/*   Updated: 2025/05/19 13:20:14 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_putstr_fd_adjust_alpha(t_flags flags, char *str, int len, int fd);
static int		ft_putstr_fd_adjust_numeric(t_flags flags, char *str, int len, int fd);
static t_flags	modif_flags(t_flags flags, int len);

int	ft_putstr_fd_adjust(t_flags flags, char *str, int len, int fd)
{
	if (is_numeric(flags.format))
		return (ft_putstr_fd_adjust_numeric(modif_flags(flags, len), str, len, fd));
	return (ft_putstr_fd_adjust_alpha(flags, str, len, fd));
}

static int	ft_putstr_fd_adjust_alpha(t_flags flags, char *str, int len, int fd)
{
	int	p;
	int	i;

	p = 0;
	i = 0;
	len = ft_trunc(flags, &str, len);
	if (!str)
		return (0);
	if (flags.right_just || flags.left_just)
		p += adjust(flags.right_just, len, ' ', fd);
	ft_putstr_fd(&str[i], fd);
	if (flags.left_just)
		p += adjust(flags.left_just, len, ' ', fd);
	free(str);
	return (p + len);
}

static int	ft_putstr_fd_adjust_numeric(t_flags flags, char *str, int len, int fd)
{
	int	p;
	int	i;

	p = 0;
	i = 0;
	if (flags.accuracy > len)
		p += adjust(flags.accuracy, len, '0', fd);
	if (flags.right_just)
		p += adjust(flags.right_just, len, ' ', fd);
	else if (flags.zeros)
		p += adjust(flags.zeros, len, '0', fd);
	ft_putstr_fd(&str[i], fd);
	if (flags.left_just)
		p += adjust(flags.left_just, len, ' ', fd);
	return (p + len);
}

static t_flags	modif_flags(t_flags flags, int len)
{
	(void)len;
	return (flags);
}
