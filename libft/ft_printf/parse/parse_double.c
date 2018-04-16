/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:17:27 by mienache          #+#    #+#             */
/*   Updated: 2018/01/15 20:17:28 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_printf.h"

void	parsedbl(t_format *flags, va_list *args)
{
	if (LEN == 3)
	{
		ARG = (long double*)ft_memalloc(sizeof(long double));
		*(long double*)(ARG) = va_arg(*args, long double);
		FBLEN = sizeof(long double);
	}
	else
	{
		ARG = (double*)ft_memalloc(sizeof(double));
		*(double*)(flags->arg) = va_arg(*args, double);
		FBLEN = sizeof(double);
	}
	if (P < 0)
		P = 6;
	if (LT == 'e')
	{
		E_P = P;
		formatedbl(flags);
	}
	else
		formatdbl(flags);
	padnum(flags);
}
