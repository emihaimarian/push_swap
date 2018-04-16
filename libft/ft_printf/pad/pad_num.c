/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:17:00 by mienache          #+#    #+#             */
/*   Updated: 2018/01/15 20:17:01 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*padsign(t_format *flags)
{
	char	*sign;
	char	*tmp;

	sign = ft_strnew(1);
	if (F_P)
		sign[0] = '+';
	else if (F_S)
		sign[0] = ' ';
	if (SA == '-')
	{
		sign[0] = '-';
		tmp = ft_strsub(ARG, 1, FBLEN - 1);
		ft_memdel((void**)&ARG);
		ARG = tmp;
		FBLEN--;
	}
	return (sign);
}

static void	subzero(t_format *flags)
{
	char	*tmp;

	if (FBLEN == 1 && P != -1 && *((char*)ARG) == '0')
	{
		*((char*)ARG) = 0;
		FBLEN = 0;
	}
	if (P > FBLEN)
	{
		tmp = ft_strnew(P - FBLEN);
		ft_memset(tmp, '0', P - FBLEN);
		tmp = ft_strjoinreplace(tmp, ARG);
		ft_memdel((void**)&ARG);
		ARG = tmp;
		FBLEN = P;
	}
}

void		padnum(t_format *flags)
{
	char	*s;
	char	*space;

	s = padsign(flags);
	subzero(flags);
	if (W > FBLEN + (s[0] ? 1 : 0))
	{
		space = ft_strnew(W - FBLEN - (s[0] ? 1 : 0));
		if (F_Z && P <= N_PRE)
			ft_memset(space, '0', W - FBLEN - (s[0] ? 1 : 0));
		else
			ft_memset(space, ' ', W - FBLEN - (s[0] ? 1 : 0));
		if (F_Z && P <= 1)
			ARG = stitch3(s, space, ARG);
		else
		{
			if (F_M)
				ARG = stitch3(s, ARG, space);
			else
				ARG = stitch3(space, s, ARG);
		}
	}
	else
		ARG = stitch2(s, ARG);
	FBLEN = ft_strlen(ARG);
}
