/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:28:57 by ygille            #+#    #+#             */
/*   Updated: 2025/05/13 15:05:59 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return the first occurence of c in s
** NULL if not found
*/
char	*ft_strchr(const char *s, int c)
{
	size_t	count;

	count = 0;
	if (s == NULL)
		return (NULL);
	while (c > 127)
		c -= 128;
	while (s[count] != '\0' && s[count] != c)
		count++;
	if (s[count] == c)
		return ((char *)&s[count]);
	else
		return (NULL);
}
