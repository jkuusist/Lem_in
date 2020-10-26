/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make connections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:56:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/10/26 10:56:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"
#include <stdlib.h>

void	make_connections(t_lem_in *lem_in)
{
	t_link *temp;
	t_room *from;
	t_room *to;
	t_connection *new;

	temp = lem_in->link;
	while (temp)
	{
		from = temp->room_one;
		to = temp->room_two;
	
	
		if (!(new = (t_connection*)malloc(sizeof(t_connection))))
			exit(-1);
		new->to_room = to;
		new->next = NULL;

		if (!from->connection)
			from->connection = new;
		else
			(from->connection)->next = new;

		temp = temp->next;
	}
}
