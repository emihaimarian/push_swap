/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:18:58 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 20:18:59 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_front(t_node **lst_head, int number)
{
	t_node	*new_node;

	if (lst_head == NULL)
	{
		if (!(new_node = (t_node*)ft_memalloc(sizeof(t_node))))
			exit(-1);
		new_node->data = number;
		new_node->next = NULL;
	}
	else
	{
		if (!(new_node = (t_node*)ft_memalloc(sizeof(t_node))))
			exit(-1);
		new_node->data = number;
		new_node->next = *lst_head;
		*lst_head = new_node;
	}
	return (1);
}
