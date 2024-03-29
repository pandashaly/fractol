/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:33:08 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/30 17:16:26 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *str, char c)
{
	size_t	count;

	if (!*str)
		return (0);
	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (count);
}

char	**ft_split(char const *str, char c)
{
	size_t	len;
	int		i;
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (ft_wordcount(str, c) + 1));
	if (!str || !arr)
		return (0);
	i = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str)
		{
			if (!ft_strchr(str, c))
				len = ft_strlen(str);
			else
				len = ft_strchr(str, c) - str;
			arr[i++] = ft_substr(str, 0, len);
			str += len;
		}
	}
	arr[i] = 0;
	return (arr);
}
