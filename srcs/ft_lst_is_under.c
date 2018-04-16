/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_is_under.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:17:24 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 20:17:25 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_is_under(t_node *list, int limit)
{
	t_node	*temp;
	int		index;

	temp = list;
	index = 0;
	while (temp != NULL)
	{
		if (temp->data <= limit)
			return (index);
		index++;
		temp = temp->next;
	}
	return (-1);
}
