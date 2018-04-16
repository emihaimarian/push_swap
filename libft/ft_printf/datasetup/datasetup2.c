/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datasetup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:16:02 by mienache          #+#    #+#             */
/*   Updated: 2018/01/15 20:16:03 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	findhhll(t_format *flags, char *tmp, int len, int i)
{
	if (tmp[i] == 'h')
	{
		if (i < len - 1 && tmp[i + 1] == 'h')
		{
			LEN = -2;
			return (i + 1);
		}
		else
			LEN = -1;
	}
	else
	{
		if (i < len - 1 && tmp[i + 1] == 'l')
		{
			LEN = 2;
			return (i + 1);
		}
		else
			LEN = 1;
	}
	return (i);
}

void		findlength(t_format *flags, char *tmp, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (tmp[i] == 'h' && LEN <= 0)
			i = findhhll(flags, tmp, len, i);
		else if (tmp[i] == 'l')
			i = findhhll(flags, tmp, len, i);
		else if (tmp[i] == 'L')
			LEN = 3;
		else if (tmp[i] == 'j')
			LEN = 4;
		else if (tmp[i] == 'z')
			LEN = 5;
		else if (tmp[i] == 't')
			LEN = 6;
		i++;
	}
}

static void	assignast(t_format *flags, va_list *args, int i, int w)
{
	int		arg;

	arg = va_arg(*args, int);
	if (w && (!(W_LEN) || i > W_LEN))
		W = arg;
	else if (!w && (!(P_LEN) || i > P_LEN))
		P = arg;
}

void		findast(t_format *flags, char *tmp, int len, va_list *args)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (tmp[i] == '*')
		{
			if (i > 0 && tmp[i - 1] == '.')
			{
				assignast(flags, args, i, 0);
				if (P < 0)
				{
					N_PRE = 1;
					P = 1;
				}
			}
			else
				assignast(flags, args, i, 1);
			i++;
		}
		else
			i++;
	}
}
