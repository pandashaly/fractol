/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 03:40:06 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/22 16:34:46 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates memory of count elements for size bytes.
 * Returns a pointer to the allocated memory.*/

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size <= 0)
		return (malloc(0));
	if (count == 0)
		return (malloc(0));
	if (SIZE_MAX / size < count)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset((unsigned char *)ptr, 0, count * size);
	return (ptr);
}
