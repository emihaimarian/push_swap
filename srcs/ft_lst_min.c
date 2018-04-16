/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:17:50 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 20:17:51 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_min(t_node *lst)
{
	t_node	*temp;
	int		min;

	temp = lst;
	min = 2147483647;
	while (temp != NULL)
	{
		min = temp->data < min ? temp->data : min;
		temp = temp->next;
	}
	return (min);
}
