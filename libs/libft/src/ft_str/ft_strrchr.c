/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:42:09 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/16 19:20:10 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last;

	last = 0;
	if (c < 0 || c > 255)
		return ((char *)str);
	while (*str != '\0')
	{
		if (*str == c)
			last = str;
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return ((char *)last);
}

/*int	main(void)
{
	const char	*s;
	int	c;

	s = "tripouille";
	c = 't' + 256;
	printf("%s\n", ft_strrchr(s, c));
	printf("%s\n", strrchr(s, c));
	return (0);
}*/
