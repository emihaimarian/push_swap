/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:18:54 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 20:18:54 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_back(t_node **lst_head, int number)
{
	t_node	*new_node;

	new_node = *lst_head;
	while (new_node->next != NULL)
		new_node = new_node->next;
	if (!(new_node->next = (t_node*)malloc(sizeof(t_node))))
		exit(-1);
	new_node->next->data = number;
	new_node->next->next = NULL;
	return (1);
}
