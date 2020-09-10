/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 12:00:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/06/10 12:26:30 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
#include <stdlib.h>

void	fill_width(t_pf *pf, char c, int len, int is_update)
{
	char *s;

	if (len > 0)
	{
		if (is_update)
			pf->len += len;
		if (!(s = ft_strnew(len)))
			exit(-1);
		ft_memset(s, c, len);
		ft_putstr(s);
		free(s);
	}
}
