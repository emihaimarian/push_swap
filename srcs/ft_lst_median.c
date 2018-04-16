/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:17:46 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 20:17:47 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_median(t_node *list, t_data *data, int level)
{
	t_node	*temp;
	int		*tab;
	int		len;
	int		i;

	len = ft_lst_len(list);
	if (!(tab = (int*)malloc(sizeof(tab) * len)))
		return (-1);
	temp = list;
	i = 0;
	while (temp != NULL)
	{
		tab[i] = (int)temp->data;
		temp = temp->next;
		i++;
	}
	ft_bubble_sort(tab, len);
	if (ft_lst_len(list) == 4)
		data->median = tab[1];
	else
		data->median = tab[(int)(len / level)];
	free(tab);
	return (0);
}
