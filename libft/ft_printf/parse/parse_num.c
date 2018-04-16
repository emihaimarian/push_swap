/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:17:30 by mienache          #+#    #+#             */
/*   Updated: 2018/01/15 20:17:31 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parsehnum(t_format *flags, va_list *args)
{
	if (LEN == -2)
	{
		ARG = (char*)ft_memalloc(sizeof(char));
		*(char*)(ARG) = va_arg(*args, int);
		FBLEN = sizeof(char);
	}
	else if (LEN == -1)
	{
		ARG = (short*)ft_memalloc(sizeof(short));
		*(short*)(ARG) = va_arg(*args, int);
		FBLEN = sizeof(short);
	}
}

void		parsenum(t_format *flags, va_list *args)
{
	if (TYPE == 'D' || LEN == 1)
	{
		ARG = (long*)ft_memalloc(sizeof(long));
		*(long*)(ARG) = va_arg(*args, long);
		FBLEN = sizeof(long);
	}
	else if (LEN < 0)
		parsehnum(flags, args);
	else if (LEN == 0)
	{
		ARG = (int*)ft_memalloc(sizeof(int));
		*(int*)(ARG) = va_arg(*args, int);
		FBLEN = sizeof(int);
	}
	else if (LEN == 2)
	{
		ARG = (long long*)ft_memalloc(sizeof(long long));
		*(long long*)(flags->arg) = va_arg(*args, long long);
		FBLEN = sizeof(long long);
	}
	formatnum(flags);
	padnum(flags);
}
