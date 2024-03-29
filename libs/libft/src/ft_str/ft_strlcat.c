/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:28:31 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/28 18:40:28 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	ans;

	i = 0;
	src_len = ft_strlen((char *)src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (size + src_len);
	ans = dst_len + src_len;
	while (src[i] && dst_len < size - 1)
		dst[dst_len++] = src[i++];
	dst[dst_len] = '\0';
	return (ans);
}
