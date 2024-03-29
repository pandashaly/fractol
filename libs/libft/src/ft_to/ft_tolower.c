/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:22:38 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/14 18:27:56 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The ft_tolower() function converts an upper-case letter 
 * to the correspond-ing lower-case letter. 
 * Argument must be representable as an unsigned char or the value of EOF. */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
