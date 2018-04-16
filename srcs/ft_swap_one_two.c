/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_one_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:19:24 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 20:19:25 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_one_two(t_node **lst_head)
{
	if ((*lst_head != NULL) && ((*lst_head)->next != NULL))
		ft_swap(&((*lst_head)->data), &((*lst_head)->next->data));
}
