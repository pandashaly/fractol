/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:04:21 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/30 13:50:50 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;
	size_t	i;

	if (s == 0)
		return (0);
	size = ft_strlen(s);
	dup = (char *)malloc(size + 1);
	if (dup == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		dup[i] = s[i];
		i++;
	}
	ft_strcpy(dup, s);
	return (dup);
}

/*int	main(void)
{
	char	*str;
	char	*dup;

	str = "";
	dup = ft_strdup(str);
	printf("real: %s\n", strdup(str));
	printf("original: %s\n", str);
	printf("duplicate: %s", dup);
	return (0);
}*/
