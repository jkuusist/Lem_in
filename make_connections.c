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
	t_connection *new_one;
	t_connection *new_two;

	temp = lem_in->link;
	while (temp)
	{
		from = temp->room_one;
		to = temp->room_two;
	
	
		if (!(new_one = (t_connection*)malloc(sizeof(t_connection))))
			exit(-1);
		new_one->to_room = to;
		new_one->next = NULL;

		if (!from->connection)
			from->connection = new_one;
		else
		{
			new_one->next = from->connection;
			from->connection = new_one;
		}

		if (!(new_two = (t_connection*)malloc(sizeof(t_connection))))
			exit(-1);
		new_two->to_room = from;
		new_two->next = NULL;

		if (!to->connection)
			to->connection = new_two;
		else
		{
			new_two->next = to->connection;
			to->connection = new_two;
		}
		temp = temp->next;
	}
}
