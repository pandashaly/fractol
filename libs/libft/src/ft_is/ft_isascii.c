/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:11:12 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/10 13:54:12 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Tests for an ASCII character, which is any character 
 * between 0 and decimal 127 inclusive.*/

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
