/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:59:10 by ygille            #+#    #+#             */
/*   Updated: 2025/05/15 16:12:02 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	adjust(int just_size, int len, char character)
{
	const int	diff = just_size - len;
	int			i;

	i = 0;
	if (diff > 0)
		i = diff;
	while (i)
	{
		ft_putchar_fd(character, STDOUT_FILENO);
		i--;
	}
	if (diff > 0)
		return (diff);
	return (0);
}
