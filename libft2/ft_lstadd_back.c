/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:40:41 by vsinagl           #+#    #+#             */
/*   Updated: 2023/11/03 19:31:23 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list *last;

	if (!lst)
		return;
	last = ft_lstlast(*lst);
	if (last == NULL)
	{
		*lst = new_node;
		new_node->next = NULL;
	}
	else
		last->next = new_node;
}
