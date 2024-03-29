/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:44:12 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/10 17:21:33 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strchr function checks for a char in a string
 * & returns a pointer to its first occurance*/

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str);
		str++;
	}
	if (str[i] == (char)c)
		return ((char *)str);
	else
		return (0);
}
/*#include <string.h>
#include <stdio.h>
int	main(void)
{
	const char	*s;
	int	c;

	s = "abcdefghijklpmnopqrstuvwxyz";
	c = 'o';
	printf("%s\n", ft_strchr(s, c));
	printf("%s\n", strchr(s, c));
	return (0);
}*/
