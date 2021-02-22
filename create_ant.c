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

void	add_ants_to_start(t_lem_in *lem_in)
{
	t_ant *temp;

	temp = lem_in->ant;
	while (temp)
	{
		temp->location = lem_in->start;
		temp = temp->next;
	}
}

t_ant	*create_ant(int num)
{
	t_ant *new;

	if (!(new = (t_ant*)malloc(sizeof(t_ant))))
		exit(-1);
	new->num = num;
	new->location = NULL;
	new->path_index = 0;
	new->next = NULL;
	return (new);
}
