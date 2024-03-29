/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:17:37 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/14 18:26:32 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Converts a lower-case letter to the corresponding upper-case letter. 
 * The argument must be representable as an unsigned char or the value of EOF. 
 * If the argument is a lower-case letter, it returns the corresponding 
 * upper-case letter if there is one; 
 * otherwise, the argument is returned unchanged.*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
