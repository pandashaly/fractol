/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:20:19 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/14 18:18:59 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function fills n bytes in memory area pointed to by s with bytes
 * of value c (converted to unsigned char).
 * Returns a pointer to the string/filled memory area s.*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	val;
	size_t			i;

	ptr = ((unsigned char *)s);
	val = ((unsigned char)c);
	i = 0;
	while (i < n)
	{
		ptr[i] = val;
		i++;
	}
	return (s);
}
