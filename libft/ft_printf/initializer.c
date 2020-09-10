/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 12:00:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/06/10 12:26:30 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initializer(t_pf *pf)
{
	pf->i = 0;
	pf->len = 0;
	pf->precision = -1;
	pf->width = 0;
	pf->spec_mask = "cCsSdiDufFoOxXpb%";
	pf->flag_mask = "#0-+ ";
	pf->mod_mask = "lLh";
}
