/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_zjt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:17:51 by mienache          #+#    #+#             */
/*   Updated: 2018/02/25 17:10:14 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parseagain(t_format *flags, va_list *args, t_da *pf)
{
	LEN = 0;
	parseswitch(flags, args, pf);
}

void		parsezjt(t_format *flags, va_list *args, t_da *pf)
{
	if (LT == 'u' || LT == 'd' || LT == 'i' || LT == 'o' || LT == 'x' ||
		LT == 'b')
	{
		if (LEN == 4)
		{
			ARG = (size_t*)ft_memalloc(sizeof(size_t));
			*(size_t*)(ARG) = va_arg(*args, size_t);
			FBLEN = sizeof(size_t);
		}
		else if (LEN == 5)
		{
			ARG = (intmax_t*)ft_memalloc(sizeof(intmax_t));
			*(intmax_t*)(ARG) = va_arg(*args, intmax_t);
			FBLEN = sizeof(intmax_t);
		}
		else if (LEN == 6)
		{
			ARG = (ptrdiff_t*)ft_memalloc(sizeof(ptrdiff_t));
			*(ptrdiff_t*)(ARG) = va_arg(*args, ptrdiff_t);
			FBLEN = sizeof(ptrdiff_t);
		}
		formatzjt(flags);
	}
	else
		parseagain(flags, args, pf);
}
