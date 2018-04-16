/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:17:34 by mienache          #+#    #+#             */
/*   Updated: 2018/01/15 20:17:35 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parsewc(t_format *flags, va_list *args)
{
	wchar_t	*tmp;

	tmp = (wchar_t*)ft_memalloc(sizeof(wchar_t) * 2);
	*tmp = va_arg(*args, wchar_t);
	ARG = ft_wstouni(tmp);
	if (*tmp)
		FBLEN = ft_strlen(ARG);
	else
		FBLEN = 1;
	ft_memdel((void**)&tmp);
}

static void	parsews(t_format *flags, va_list *args)
{
	wchar_t	*tmp;

	tmp = va_arg(*args, wchar_t*);
	if (tmp)
	{
		ARG = ft_wstouni(tmp);
		FBLEN = ft_strlen(ARG);
	}
	else
	{
		ARG = ft_strdup("(null)");
		FBLEN = 6;
		LEN = 0;
	}
	if (N_PRE && P < FBLEN)
		P = FBLEN;
}

void		parsechar(t_format *flags, va_list *args)
{
	if (TYPE == 'C')
		LEN = 1;
	if (LEN == 1)
		parsewc(flags, args);
	else
	{
		ARG = (char*)ft_memalloc(sizeof(char) * 2);
		*(char*)(ARG) = va_arg(*args, int);
		FBLEN = 1;
	}
	padcs(flags);
}

void		parsestr(t_format *flags, va_list *args)
{
	char	*tmp;

	if (TYPE == 'S')
		LEN = 1;
	if (LEN == 1)
		parsews(flags, args);
	else
	{
		tmp = va_arg(*args, char*);
		if (tmp)
		{
			ARG = ft_strdup(tmp);
			FBLEN = ft_strlen((char*)(ARG));
		}
		else
		{
			ARG = ft_strdup("(null)");
			FBLEN = 6;
		}
		if (N_PRE && P < FBLEN)
			P = FBLEN;
	}
	padcs(flags);
}
