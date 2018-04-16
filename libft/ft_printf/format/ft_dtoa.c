/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:16:36 by mienache          #+#    #+#             */
/*   Updated: 2018/01/15 20:16:37 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_printf.h"

#define EPSILON 1e-15

char		ft_dtoa(double n, int p, char *frac)
{
	long double		holder;
	int				i;
	long double		tens;
	char			lastdig;

	tens = 1;
	i = 0;
	while (i < p)
	{
		holder = n * tens;
		frac[i] = (long)((holder - ((long long)holder)) * 10) + 48;
		tens *= 10;
		i++;
	}
	holder = n * tens;
	lastdig = (long)((holder - ((long)holder)) * 10);
	return (lastdig);
}

static int	ft_firstdig(double n, char *frac, t_format *flags)
{
	long double		holder;
	long double		tens;
	int				i;

	i = 0;
	tens = 1;
	if (fabs(n - (long)n) > EPSILON)
	{
		while (!i)
		{
			holder = n * tens;
			i = (long)((holder - ((long long)holder)) * 10);
			tens *= 10;
			E_L--;
		}
		frac[0] = i + 48;
	}
	else
	{
		holder = n;
		frac[0] = (long)((holder - ((long long)holder)) * 10) + 48;
		tens = 10;
	}
	return (tens);
}

char		ft_etoa(double n, char *frac, t_format *flags)
{
	long double		holder;
	long double		tens;
	char			lastdig;
	int				i;

	tens = ft_firstdig(n, frac, flags);
	i = 1;
	while (i < E_P)
	{
		holder = n * tens;
		frac[i++] = (long)((holder - ((long long)holder)) * 10) + 48;
		tens *= 10;
	}
	holder = n * tens;
	lastdig = (long)((holder - ((long)holder)) * 10);
	return (lastdig);
}

char		*adddigit(char *dec)
{
	char			*tmp;
	int				i;
	int				len;

	len = ft_strlen(dec);
	tmp = ft_strnew(len + 1);
	i = 0;
	if (dec[i] == '-')
		tmp[i++] = '-';
	tmp[i] = '1';
	while (i < len)
	{
		tmp[i + 1] = dec[i];
		i++;
	}
	ft_memdel((void**)&dec);
	return (tmp);
}

int			rounding(char *dec, int i)
{
	if (dec[i] <= '9' && dec[i] >= '0')
	{
		if (dec[i] < '9')
			(dec[i])++;
		else
		{
			dec[i] = '0';
			if (!i || dec[i - 1] == '-')
				return (1);
			else
				return (rounding(dec, i - 1));
		}
	}
	return (0);
}
