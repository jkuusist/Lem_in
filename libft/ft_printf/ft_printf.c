/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:21:34 by jkuusist          #+#    #+#             */
/*   Updated: 2020/06/10 12:26:30 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
#include <stdarg.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...)
{
	t_pf	*pf;
	int		ret;

	if (!(pf = (t_pf*)malloc(sizeof(t_pf))))
		return (-1);
	pf->format = format;
	initializer(pf);
	if (format)
	{
		if (ft_strchr(format, '%'))
		{
			va_start(pf->args, format);
			pf->len = handle_specs(pf);
			va_end(pf->args);
		}
		else
		{
			ft_putstr(format);
			free(pf);
			return (ft_strlen(format));
		}
	}
	ret = pf->len;
	free(pf);
	return (ret);
}
