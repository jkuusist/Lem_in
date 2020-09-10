/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 12:16:02 by jkuusist          #+#    #+#             */
/*   Updated: 2019/10/25 12:16:02 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putchar_pf(char c, t_pf *pf, int is_update)
{
	if (is_update)
		pf->len++;
	write(1, &c, 1);
}
