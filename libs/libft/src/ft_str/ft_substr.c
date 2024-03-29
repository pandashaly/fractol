/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:53:52 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/30 10:51:09 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}

/*int	main(void)
{
	char *result1 = ft_substr("hello choom", 6, 5);
	printf("Test1: %s\n", result1);

	char *result2 = ft_substr("Hello", 2, 0);
	printf("Test2: %s\n", result2);

	char *result3 = ft_substr("42 London", 3, 6);
	printf("Test3: %s\n", result3);

	char *result4 = ft_substr("Testing", 0, 7);
	printf("Test4: %s\n", result4);

	char *result5 = ft_substr(NULL, 2, 3);
	printf("Test5: %s\n", result5);

	free(result1);
	free(result2);
	free(result3);
	free(result4);
	free(result5);

	return (0);
}*/
