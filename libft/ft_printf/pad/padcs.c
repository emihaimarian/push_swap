/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:17:12 by mienache          #+#    #+#             */
/*   Updated: 2018/01/15 20:17:13 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ubytes(unsigned char c)
{
	if (c <= (MB_CUR_MAX == 1 ? 0xFF : 0x7F))
		return (1);
	else if (c < 0xE0)
		return (2);
	else if (c < 0xF0)
		return (3);
	else
		return (4);
}

static void	padw2(t_format *flags)
{
	char	*t1;
	char	*t2;

	t1 = ft_strnew(W - FBLEN);
	t2 = ft_strndup(ARG, FBLEN);
	ft_memdel((void**)&ARG);
	if (F_Z)
		ft_memset(t1, '0', W - FBLEN);
	else
		ft_memset(t1, ' ', W - FBLEN);
	if (F_M)
	{
		ARG = ft_pfstrnj(t2, FBLEN, t1, W - FBLEN);
		ft_memdel((void**)&t1);
	}
	else
	{
		ARG = ft_pfstrnj(t1, W - FBLEN, t2, FBLEN);
		ft_memdel((void**)&t2);
	}
	FBLEN = W;
}

static void	padw(t_format *flags)
{
	char	*t1;
	int		b;
	int		i;

	if (P < FBLEN && ((LT == 's' && P >= 0) || (LT == 'c' && P > 0)))
	{
		i = 0;
		b = 0;
		while (b <= P)
		{
			i = ft_ubytes(((char*)ARG)[b]);
			b += i;
		}
		b -= i;
		t1 = ft_strsub(ARG, 0, b);
		ft_memdel((void**)&ARG);
		ARG = t1;
		FBLEN = b;
	}
	if (W > FBLEN && W)
		padw2(flags);
}

static void	padcs2(t_format *flags)
{
	char	*t1;
	char	*t2;

	t1 = ft_strnew(W - FBLEN);
	t2 = ft_strndup(ARG, FBLEN);
	ft_memdel((void**)&ARG);
	if (F_Z)
		ft_memset(t1, '0', W - FBLEN);
	else
		ft_memset(t1, ' ', W - FBLEN);
	if (F_M)
	{
		ARG = ft_pfstrnj(t2, FBLEN, t1, W - FBLEN);
		ft_memdel((void**)&t1);
	}
	else
	{
		ARG = ft_pfstrnj(t1, W - FBLEN, t2, FBLEN);
		ft_memdel((void**)&t2);
	}
	FBLEN = W;
}

void		padcs(t_format *flags)
{
	char	*t1;

	if (TYPE == 'C' || TYPE == 'S' || LEN == 1)
		padw(flags);
	else
	{
		if (P < FBLEN && ((LT == 's' && P >= 0) || (LT == 'c' && P > 0)))
		{
			t1 = ft_strsub(ARG, 0, P);
			ft_memdel((void**)&ARG);
			ARG = t1;
			FBLEN = P;
		}
		if (W > FBLEN && W)
			padcs2(flags);
	}
}
