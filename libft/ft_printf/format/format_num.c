/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:16:30 by mienache          #+#    #+#             */
/*   Updated: 2018/01/15 20:16:31 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		formatnum(t_format *flags)
{
	char		*numstr;

	if (TYPE == 'D')
		LEN = 1;
	if (LEN == -2)
		numstr = ft_itoa(*(char*)ARG);
	else if (LEN == -1)
		numstr = ft_itoa(*(short*)ARG);
	else if (LEN == 0)
		numstr = ft_itoa(*(int*)ARG);
	else
		numstr = ft_itoa(*(long*)ARG);
	ft_memdel((void**)&ARG);
	ARG = numstr;
	FBLEN = ft_strlen(ARG);
}

static void	ft_alllower(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}

static int	findbase(t_format *flags)
{
	int			base;

	if (LT == 'u')
		base = 10;
	else if (LT == 'o')
		base = 8;
	else if (LT == 'x' || LT == 'p')
		base = 16;
	else
		base = 2;
	return (base);
}

void		formatunum(t_format *flags)
{
	char		*numstr;
	int			base;

	base = findbase(flags);
	if (LEN == -2)
		numstr = ft_itoa_base(*(unsigned char*)ARG, base);
	else if (LEN == -1)
		numstr = ft_itoa_base(*(unsigned short*)ARG, base);
	else if (LEN == 0)
		numstr = ft_itoa_base(*(unsigned int*)ARG, base);
	else
		numstr = ft_itoa_base(*(unsigned long*)ARG, base);
	if (TYPE == 'x' || TYPE == 'p')
		ft_alllower(numstr);
	ft_memdel((void**)&ARG);
	ARG = numstr;
	FBLEN = ft_strlen(ARG);
	F_P = 0;
	F_S = 0;
}

void		formatzjt(t_format *flags)
{
	if (LT == 'i' || LT == 'd')
		formatnum(flags);
	else
		formatunum(flags);
	padnum(flags);
}
