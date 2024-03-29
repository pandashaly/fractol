/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:08:29 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/10 17:25:33 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*checks whether the given value is an alphabetical char (uppercase /lowercase)
 * or if it's a decimal digit (0 - 9) */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
