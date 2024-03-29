/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:38:31 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/22 16:52:00 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ASCII to intiger:
 *
 * Converts the initial portion of an ASCII string pointed to by str 
 * to an intiger and returns the converted value (result) or 0 on error.*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	i;
	long long	size;
	size_t		result;

	i = 0;
	size = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			size = -1;
		else
			size = 1;
		i++;
	}
	while ((str[i] != '\0') && ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result *= size;
	return (result);
}
/*#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	const char	*str;

	str = " 	-+1234abd678";
	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
	return (0);
}*/
