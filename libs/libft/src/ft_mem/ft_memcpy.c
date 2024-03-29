/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:56:46 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/30 13:54:22 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Copies n bytes from memory area src to memory area dst.
 * The two memory areas should not overlap.
 * If there is memory overlap, use memmove instead.
 * Returns pointer to dst.*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	d = ((unsigned char *)dst);
	s = ((unsigned const char *)src);
	i = 0;
	if (!dst && !src)
		return (0);
	if (n == 0)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
