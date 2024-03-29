/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:30:37 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/10 14:32:42 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Like memcpy, memmove copies n bytes from src to dst, but pverlap is handled.
 * They're copied into a temporaty array which doesn't overlap src or dst,
 * and is then copied into the dst. 
 * Returns a pointer to dst*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s = src;

	d = (char *)dst;
	if (!d && !s)
		return (0);
	if (d == s)
		return (d);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	if (d > s)
	{
		d += n -1;
		s += n - 1;
		while (n--)
			*d-- = *s--;
	}
	return (dst);
}
