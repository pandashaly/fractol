/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:59:25 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/16 19:02:48 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void	*s1, const	void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	if (n == 0)
		return (0);
	if (n > 0)
	{
		c1 = ((unsigned char *)s1);
		c2 = ((unsigned char *)s2);
		while (--n > 0 && *c1 == *c2)
		{
			c1++;
			c2++;
		}
		return (*c1 - *c2);
	}
	return (0);
}
