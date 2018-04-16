/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:16:22 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 20:16:23 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_delete_last(t_node **lst_head)
{
	t_node	*tmp;
	t_node	*second_tmp;
	int		deleted_value;

	tmp = *lst_head;
	if ((*lst_head)->next == NULL)
	{
		deleted_value = (*lst_head)->data;
		free(lst_head);
		lst_head = NULL;
	}
	else
	{
		while (tmp->next != NULL)
		{
			second_tmp = tmp;
			tmp = tmp->next;
		}
		deleted_value = tmp->data;
		free(second_tmp->next);
		second_tmp->next = NULL;
	}
	return (deleted_value);
}
