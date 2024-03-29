/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:25:52 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/22 18:58:21 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Computes and returns the number of bytes/length of the string pointed to 
 * by str excluding the null terminator.*/

#include "libft.h"
#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
