/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_issorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:17:30 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 20:17:31 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_is_sorted(t_node *list)
{
	t_node	*temp;

	temp = list;
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data)
			return (-1);
		temp = temp->next;
	}
	return (1);
}
