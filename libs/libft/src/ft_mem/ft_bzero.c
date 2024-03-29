/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:40:54 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/21 22:24:23 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Replaces n zeroed bytes to the string s, if n is zero, bzero does nothing*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = ((unsigned char *)s);
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
