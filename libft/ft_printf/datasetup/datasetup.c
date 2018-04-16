/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datasetup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:15:57 by mienache          #+#    #+#             */
/*   Updated: 2018/02/25 17:07:26 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_numconv = "diouxXDOUeEfFgGaAp";

static void	findw(t_format *flags, char *tmp, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (ft_isdigit(tmp[i]) && tmp[i] != '0')
		{
			if (tmp[i - 1] != '.')
			{
				W = ft_atoi(tmp + i);
				W_LEN = i;
			}
			while (ft_isdigit(tmp[i]))
				i++;
		}
		else
			i++;
	}
}

static void	findp(t_format *flags, char *tmp, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (tmp[i] == '.')
		{
			P = 0;
			while (!ft_isdigit(tmp[i]) && i < len)
				i++;
			if (ft_isdigit(tmp[i]))
			{
				P = ft_atoi(tmp + i);
				P_LEN = i;
				while (ft_isdigit(tmp[i]))
					i++;
			}
		}
		else
			i++;
	}
}

static void	findflags(t_format *flags, char *tmp, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (tmp[i] == '-')
			F_M = 1;
		else if (tmp[i] == '+')
			F_P = 1;
		else if (tmp[i] == ' ')
			F_S = 1;
		else if (tmp[i] == '0' && tmp[i - 1] != '.' && !ft_isdigit(tmp[i - 1]))
			F_Z = 1;
		else if (tmp[i] == '#')
			F_PND = 1;
		i++;
	}
}

void		datasetup(t_format *flags, char *format, va_list *args)
{
	int		len;
	char	*tmp;

	tmp = format;
	tmp++;
	P = -1;
	len = ft_strchr(tmp, TYPE) - tmp;
	findflags(flags, tmp, len);
	findw(flags, tmp, len);
	findp(flags, tmp, len);
	findast(flags, tmp, len, args);
	if (W < 0)
	{
		W *= -1;
		F_M = 1;
	}
	if (F_M || (!P && ft_strchr(g_numconv, TYPE)))
		F_Z = 0;
	if (F_P)
		F_S = 0;
	findlength(flags, tmp, len);
}
