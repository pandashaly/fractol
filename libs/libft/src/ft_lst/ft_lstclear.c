/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:20:36 by ssottori          #+#    #+#             */
/*   Updated: 2024/02/05 14:20:46 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buff;

	if (!lst || !del)
		return ;
	while ((*lst))
	{
		buff = (*lst)->next;
		ft_lstdelone((*lst), del);
		(*lst) = buff;
	}
}
