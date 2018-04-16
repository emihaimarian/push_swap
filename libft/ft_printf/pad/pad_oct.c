/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_oct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:17:04 by mienache          #+#    #+#             */
/*   Updated: 2018/01/15 20:22:26 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*padowid(t_format *flags)
{
	char	*tmp;
	char	*o;

	o = ft_strnew(1);
	o[0] = '0';
	if (P == -1)
		P = 0;
	if (FBLEN == 1 && P != -1 && *((char*)ARG) == '0')
	{
		*((char*)ARG) = 0;
		FBLEN = 0;
	}
	if (P > FBLEN)
	{
		tmp = ft_strnew(P - FBLEN - 1);
		ft_memset(tmp, '0', P - FBLEN - 1);
		tmp = ft_strjoinreplace(tmp, ARG);
		ft_memdel((void**)&ARG);
		ARG = tmp;
		FBLEN = P - 1;
	}
	return (o);
}

void		padoct(t_format *flags)
{
	char	*o;
	char	*space;

	o = padowid(flags);
	if (W > FBLEN + 1)
	{
		space = ft_strnew(W - FBLEN - 1);
		ft_memset(space, ((F_Z && P <= 1) ? '0' : ' '), W - FBLEN - 1);
		if (F_Z)
			ARG = stitch3(o, space, ARG);
		else
		{
			if (F_M)
				ARG = stitch3(o, ARG, space);
			else
				ARG = stitch3(space, o, ARG);
		}
	}
	else
		ARG = stitch2(o, ARG);
	FBLEN = ft_strlen(ARG);
}
