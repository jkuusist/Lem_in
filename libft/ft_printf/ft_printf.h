/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 11:03:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/07/02 11:51:30 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct	s_pf
{
	const char	*format;
	char		*formatcpy;
	va_list		args;
	int			i;
	int			len;
	long		precision;
	long		width;
	char		flags[6];
	char		*spec_mask;
	char		spec_flag;
	char		*flag_mask;
	char		*mod_mask;
	char		mod_flag[5];
}				t_pf;

int				ft_printf(const char *format, ...);
int				handle_specs(t_pf *pf);
void			print_format_str(t_pf *pf, int count);
void			initializer(t_pf *pf);
int				numlen(long long num, int base);
void			handle_flags(t_pf *pf);
void			handle_width(t_pf *pf);
void			handle_precision(t_pf *pf);
void			handle_modifiers(t_pf *pf);
void			handle_specifier(t_pf *pf);
void			print_format(t_pf *pf);
void			reinit(t_pf *pf);
void			fill_width(t_pf *pf, char c, int len, int is_update);
void			double_to_str(double dub, char *result,
				int precision, char *flags);
void			print_char(t_pf *pf);
void			print_str(t_pf *pf);
void			print_int(t_pf *pf);
void			print_double(t_pf *pf);
void			print_oct(t_pf *pf);
void			print_hex(t_pf *pf);
void			print_ptr(t_pf *pf);
void			print_bin(t_pf *pf);
void			print_percent(t_pf *pf);
char			*ft_strndup(const char *s1, unsigned int n);
void			ft_putchar_pf(char c, t_pf *pf, int is_update);
void			print_negative_int(t_pf *pf, long long num);
void			print_positive_int(t_pf *pf, long long num);

#endif
