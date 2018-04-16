/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:15:56 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 20:16:03 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubble_sort(int *tab, int len)
{
	int i;
	int	is_sort;

	is_sort = 0;
	while (is_sort == 0)
	{
		is_sort = 1;
		i = 0;
		while (i < len - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				is_sort = 0;
			}
			i++;
		}
	}
}
