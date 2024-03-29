/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:03:58 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/17 18:09:47 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((n > 0) && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	if (*s1 == *s2)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/*int	main(void)
{
	const char	*s1;
	const char	*s2;
	int	n;
	int	ans;

	n = 3;
	s1 = "1234";
	s2 = "1235";
	ans = strncmp(s1, s2, n);
	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d\n", ans);
	return (0);
}*/
