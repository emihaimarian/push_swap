/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:16:17 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 20:16:18 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_delete_first(t_node **lst_head)
{
	t_node	*old_head;
	int		deleted_value;

	old_head = NULL;
	deleted_value = -1;
	if (*lst_head == NULL)
		return (-1);
	old_head = *lst_head;
	deleted_value = (*lst_head)->data;
	*lst_head = (*lst_head)->next;
	free(old_head);
	return (deleted_value);
}
