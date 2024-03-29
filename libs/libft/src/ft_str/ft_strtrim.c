/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:32:57 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/22 12:14:57 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	str = 0;
	if (!set || !s1)
		return (NULL);
	if (s1 != 0 && set != 0)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (end > start && ft_strchr(set, s1[end - 1]))
			end--;
		str = (char *)malloc(sizeof(char) * (end - start + 1));
		if (str)
			ft_strlcpy(str, &s1[start], end - start + 1);
	}
	return (str);
}

/*int	main(void)
{
	printf("Test1: %s\n", ft_strtrim("abqbc", "abc")); //q
	printf("Test2: %s\n", ft_strtrim("hello 42", "ell")); //o 42
	printf("Test3: %s\n", ft_strtrim("", "")); //empty
	printf("Test4: %s\n", ft_strtrim(NULL, "abc")); //empty
	printf("Test5: %s\n", ft_strtrim("Donut", NULL)); //Donut
	printf("Test6: %s\n", ft_strtrim("abcdefgh", "de")); //fgh
	printf("Test7: %s\n", ft_strtrim("abcdonutxyz", "abcxyz")); //donut

	return (0);
}*/
