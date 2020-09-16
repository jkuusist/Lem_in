/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lem_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:25:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/09/16 11:25:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"
#include <stdlib.h>

t_lem_in	*create_lem_in(void)
{
	t_lem_in *new;

	if (!(new = (t_lem_in*)malloc(sizeof(t_lem_in))))
		exit(-1);
	new->map = NULL;
	return (new);
}
