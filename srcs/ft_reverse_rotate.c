/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:19:17 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 20:19:17 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_reverse_rotate(t_node **lst_head)
{
	int last_to_first;

	if (*lst_head != NULL && (*lst_head)->next != NULL)
	{
		last_to_first = -1;
		last_to_first = ft_delete_last(&(*lst_head));
		if (ft_push_front(&(*lst_head), last_to_first) == -1)
			return (-1);
	}
	return (1);
}
