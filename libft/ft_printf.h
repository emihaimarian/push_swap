/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:45:23 by mienache          #+#    #+#             */
/*   Updated: 2018/02/25 17:06:23 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdint.h>
# include <wchar.h>
# include <stddef.h>
# include <stdarg.h>

typedef struct		s_format
{
	char			flag_zero;
	char			flag_plus;
	char			flag_minus;
	char			flag_space;
	char			flag_pound;
	char			negative_precision;
	char			width_asterix;
	char			conversion;
	int				length;
	int				width;
	int				precision;
	int				width_len;
	int				precision_len;
	int				e_len;
	int				e_precision;
	int				bytelen;
	void			*arg;
}					t_format;
typedef struct		s_da
{
	char			*str;
	char			*old;
	int				bytelen;
}					t_da;

# define STR pf->str
# define OLD pf->old
# define BLEN pf->bytelen
# define TYPE flags->conversion
# define LT ft_tolower(flags->conversion)
# define LEN flags->length
# define ARG flags->arg
# define FBLEN flags->bytelen
# define F_P flags->flag_plus
# define F_S flags->flag_space
# define F_PND flags->flag_pound
# define F_M flags->flag_minus
# define F_Z flags->flag_zero
# define N_PRE flags->negative_precision
# define P flags->precision
# define P_LEN flags->precision_len
# define E_P flags->e_precision
# define E_L flags->e_len
# define W flags->width
# define W_LEN flags->width_len
# define SA ((char*)flags->arg)[0]

int					ft_printf(const char *restrict format, ...);
void				datasetup(t_format *flags, char *format, va_list *args);
void				findast(t_format *flags, char *tmp, int len, va_list *args);
void				findlength(t_format *flags, char *tmp, int len);
void				parseswitch(t_format *flags, va_list *args, t_da *pf);
void				insertformat(t_da *pf, int len);
char				*ft_pfstrnj(char *s1, size_t len1, char *s2, size_t len2);
void				cutformat(t_da *pf, t_format *flags);
void				parsezjt(t_format *flags, va_list *args, t_da *pf);
void				parsedbl(t_format *flags, va_list *args);
void				parsenum(t_format *flags, va_list *args);
void				parsechar(t_format *flags, va_list *args);
void				parsestr(t_format *flags, va_list *args);
void				parseunum(t_format *flags, va_list *args);
void				formatdbl(t_format *flags);
void				formatedbl(t_format *flags);
void				formatnum(t_format *flags);
void				formatunum(t_format *flags);
void				formatzjt(t_format *flags);
void				padcs(t_format *flags);
void				padnum(t_format *flags);
void				padhex(t_format *flags);
void				padoct(t_format *flags);
void				padgen(t_format *flags);
char				ft_dtoa(double n, int p, char *frac);
char				ft_etoa(double n, char *frac, t_format *flags);
char				*adddigit(char *dec);
int					rounding(char *dec, int i);
char				*makeinfnan(double n);
char				*adddecpt(char *dec, int len);
void				*stitch2(char *s1, char *s2);
void				*stitch3(char *s1, char *s2, char *s3);

#endif
