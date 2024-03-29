/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:25:55 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/21 14:04:31 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (!src || !dst)
		return (0);
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
		return (src_len);
	dst[i] = '\0';
	return (src_len);
}
/*int	main(void)
{
	char	dst[10] = "Hello ";
	const char	*src;
	size_t	n;
	size_t	result;

	//dst = "Hello ";
	src = "Chooms!";
	n = 0;
	result = strlcpy(dst, src, 4);
	printf("%zu\n", ft_strlcpy(dst, src, n));
	printf("%zu\n", result);
	printf("%s\n", dst);
	return (0);
}*/
