/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_double2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:12:31 by mienache          #+#    #+#             */
/*   Updated: 2018/01/15 20:16:27 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_printf.h"

static char	*makeexp(t_format *flags)
{
	char	*sign;
	char	*tmp;
	char	*tmp2;

	sign = ft_strnew(2);
	sign[0] = TYPE;
	if (E_L >= 0)
		sign[1] = '+';
	else
	{
		sign[1] = '-';
		E_L = -(E_L);
	}
	tmp = ft_itoa(E_L);
	if (ft_strlen(tmp) == 1)
	{
		tmp2 = ft_strjoin("0", tmp);
		ft_memdel((void**)&tmp);
		tmp = tmp2;
	}
	tmp2 = ft_strjoin(sign, tmp);
	ft_memdel((void**)&sign);
	ft_memdel((void**)&tmp);
	return (tmp2);
}

static int	eprecision(t_format *flags, char **str, char lastdig)
{
	char			*tmp;
	unsigned int	len;

	len = ((*str)[0] == '-' ? 2 : 1) + P;
	if ((*str)[len])
		lastdig = (int)((*str)[len] - 48);
	if (lastdig > 4)
	{
		if (rounding(*str, len - 1))
			*str = adddigit(*str);
	}
	if (ft_strlen(*str) > len)
	{
		tmp = ft_strsub(*str, 0, len);
		ft_memdel((void**)str);
		*str = tmp;
	}
	return (((*str)[0] == '-' ? 2 : 1));
}

static char	makeedbl2(t_format *flags, double n, char **str, int len)
{
	char	*frac;
	char	lastdig;

	E_P -= (E_L >= 0 ? 0 : E_L);
	frac = ft_strnew(E_P);
	if ((*str)[0] == 0 || ((*str)[0] == '-' && (*str)[1] == 0))
	{
		lastdig = ft_etoa(n, frac, flags);
		E_L++;
	}
	else
	{
		E_P -= len - 1;
		lastdig = ft_dtoa(n, E_P, frac);
	}
	*str = ft_strjoinreplace(*str, frac);
	ft_memdel((void**)&frac);
	return (lastdig);
}

static char	*makeedbl(t_format *flags)
{
	double		n;
	char		*str;
	int			len;
	char		*tmp;

	n = *(double*)ARG;
	str = ft_strnew(1);
	len = 0;
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
		len++;
	}
	tmp = ft_itoa((long long)n);
	len = ft_strlen(tmp);
	if (len == 1 && tmp[0] == '0')
		tmp[0] = 0;
	E_L += len - (tmp[0] ? 1 : 2);
	str = ft_strjoinreplace(str, tmp);
	ft_memdel((void**)&tmp);
	len = makeedbl2(flags, n, &str, len);
	E_P = eprecision(flags, &str, len);
	return (str);
}

void		formatedbl(t_format *flags)
{
	char	*str;
	char	*tmp;

	if (isinf(*(double*)ARG) || isnan(*(double*)ARG))
	{
		str = makeinfnan(*(double*)ARG);
		P = -1;
	}
	else
	{
		if (LEN == 3)
			str = makeedbl(flags);
		else
			str = makeedbl(flags);
		str = adddecpt(str, E_P);
	}
	tmp = makeexp(flags);
	str = ft_strjoinreplace(str, tmp);
	ft_memdel((void**)&tmp);
	ft_memdel((void**)&ARG);
	ARG = str;
	FBLEN = ft_strlen(ARG);
}
