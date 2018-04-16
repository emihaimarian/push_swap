/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:19:08 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 20:19:09 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_min(t_node **stack_a, t_node **stack_b, int pos, int middle)
{
	if (pos == 0)
	{
		ft_push_ab(&(*stack_a), &(*stack_b));
		ft_putendl("pb");
	}
	else if (pos < middle)
	{
		ft_rotate(&(*stack_a));
		ft_putendl("ra");
	}
	else if (pos >= middle)
	{
		ft_reverse_rotate(&(*stack_a));
		ft_putendl("rra");
	}
	return (0);
}
