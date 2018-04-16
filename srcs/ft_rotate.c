/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:19:20 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 20:19:21 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_node **lst_head)
{
	t_node *lst;

	lst = *lst_head;
	if (*lst_head != NULL)
	{
		while (lst->next != NULL)
		{
			ft_swap(&(lst->data), &(lst->next->data));
			lst = lst->next;
		}
	}
}
