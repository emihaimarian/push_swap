/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_switch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:17:38 by mienache          #+#    #+#             */
/*   Updated: 2018/02/25 17:09:54 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsen(t_format *flags, va_list *args, t_da *pf)
{
	ARG = va_arg(*args, int*);
	FBLEN = sizeof(int);
	*((int*)ARG) = BLEN;
}

void	parsepct(t_format *flags)
{
	ARG = ft_strndup(&TYPE, 1);
	FBLEN = 1;
	padgen(flags);
}

void	parseptr(t_format *flags, va_list *args)
{
	ARG = (void**)ft_memalloc(sizeof(void*));
	*(void**)((ARG)) = va_arg(*args, void*);
	FBLEN = sizeof(void*);
	LEN = 1;
	formatunum(flags);
	padhex(flags);
}

void	parseswitch(t_format *flags, va_list *args, t_da *pf)
{
	if (TYPE == 'p')
		parseptr(flags, args);
	else if (TYPE == 'n')
		parsen(flags, args, pf);
	else if (LEN > 3)
		parsezjt(flags, args, pf);
	else if (LT == 'f' || LT == 'e' || LT == 'g' || LT == 'a')
		parsedbl(flags, args);
	else if (LT == 'c')
		parsechar(flags, args);
	else if (LT == 's')
		parsestr(flags, args);
	else if (LT == 'u' || LT == 'o' || LT == 'x' || TYPE == 'b')
		parseunum(flags, args);
	else if (LT == 'd' || LT == 'i')
		parsenum(flags, args);
	else
		parsepct(flags);
}
