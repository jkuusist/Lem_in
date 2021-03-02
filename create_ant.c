/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:26:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/10/23 11:26:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"
#include <stdlib.h>

t_ant	*create_ant(int num)
{
	t_ant *new;

	if (!(new = (t_ant*)malloc(sizeof(t_ant))))
		exit(-1);
	new->num = num;
	new->path = NULL;
	new->next = NULL;

	return (new);
}
