/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:17:40 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 20:17:41 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_max(t_node *lst)
{
	t_node	*temp;
	int		max;

	temp = lst;
	max = -2147483648;
	while (temp != NULL)
	{
		max = temp->data > max ? temp->data : max;
		temp = temp->next;
	}
	return (max);
}
