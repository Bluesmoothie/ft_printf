/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public_ft_printf.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:36:59 by ygille            #+#    #+#             */
/*   Updated: 2025/05/19 12:00:11 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUBLIC_FT_PRINTF_H
# define PUBLIC_FT_PRINTF_H

# include <libft.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);

#endif