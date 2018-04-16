/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_switch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:17:08 by mienache          #+#    #+#             */
/*   Updated: 2018/01/15 20:17:09 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	padgen2(t_format *flags)
{
	char	*t1;
	char	*t2;

	t1 = ft_strnew(W - FBLEN);
	t2 = ft_strdup(ARG);
	ft_memdel((void**)&ARG);
	if (F_Z)
		ft_memset(t1, '0', W - FBLEN);
	else
		ft_memset(t1, ' ', W - FBLEN);
	if (F_M)
	{
		ARG = ft_strjoinreplace(t2, t1);
		ft_memdel((void**)&t1);
	}
	else
	{
		ARG = ft_strjoinreplace(t1, t2);
		ft_memdel((void**)&t2);
	}
	FBLEN = W;
}

void		padgen(t_format *flags)
{
	if (W > FBLEN)
		padgen2(flags);
}

void		*stitch3(char *s1, char *s2, char *s3)
{
	char	*str;

	str = ft_strjoinreplace(s1, s2);
	ft_memdel((void**)&s2);
	str = ft_strjoinreplace(str, s3);
	ft_memdel((void**)&s3);
	return (str);
}

void		*stitch2(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoinreplace(s1, s2);
	ft_memdel((void**)&s2);
	return (str);
}
