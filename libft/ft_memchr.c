/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:25:15 by ygille            #+#    #+#             */
/*   Updated: 2025/05/13 15:05:30 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Search for the first occurence of c in s on the first n bytes
** return the resulting occurence if found or NULL if not or on error
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;

	count = 0;
	while (count < n)
	{
		if (((unsigned char *)s)[count] == (unsigned char)c)
			return ((void *)s + count);
		count++;
	}
	return (NULL);
}
