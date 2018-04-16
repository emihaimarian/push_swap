/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:16:40 by mienache          #+#    #+#             */
/*   Updated: 2018/02/25 17:08:07 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pfstrnj(char *s1, size_t len1, char *s2, size_t len2)
{
	char	*s;
	size_t	n;
	size_t	i;
	size_t	j;

	n = (size_t)(len1 + len2);
	s = ft_strnew(n);
	if (!s)
		return (s);
	i = 0;
	while (i < len1)
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
		s[i++] = s2[j++];
	ft_memdel((void**)&s1);
	return (s);
}

void	insertformat(t_da *pf, int len)
{
	char	*t1;
	int		end;

	t1 = ft_strsub(OLD, 0, len);
	STR = ft_pfstrnj(STR, BLEN, t1, len);
	ft_memdel((void**)&t1);
	if (OLD[len])
	{
		end = ft_strchr(OLD, '\0') - OLD;
		t1 = ft_strsub(OLD, len, end);
		ft_memdel((void**)&(OLD));
		OLD = t1;
	}
	else
	{
		ft_memdel((void**)&(OLD));
		OLD = ft_strnew(0);
	}
	BLEN += len;
}

void	cutformat(t_da *pf, t_format *flags)
{
	char	*t1;
	char	*t2;
	int		len;

	t1 = ft_strchr(OLD + 1, TYPE) + 1;
	len = ft_strlen(t1);
	t2 = ft_strsub(t1, 0, len);
	ft_memdel((void**)&(OLD));
	OLD = t2;
	if (TYPE != 'n')
	{
		STR = ft_pfstrnj(STR, BLEN, ARG, FBLEN);
		if (ARG && (*((char*)ARG) || LT == 'c'))
			BLEN += FBLEN;
		ft_memdel((void**)&(ARG));
	}
}
