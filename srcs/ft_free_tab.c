/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:16:26 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 20:16:27 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i]);
	ft_strdel(tab);
}
