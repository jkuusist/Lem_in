/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:16:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/10/29 10:16:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"
#include <stdlib.h>

#include "libft/libft.h"
#include <stdio.h>

void depth_first_traversal(t_lem_in *lem_in, t_room *room, t_path_array *path_array, t_room_array *current_path)
{
	t_connection *connection;

	connection = room->connection;

	insert_room_into_array(current_path, room);
	room->is_visited = 1;
	if (connection->to_room->is_end)
	{
		printf("PATH IS:\n");
		for (unsigned int i = 0; i < current_path->used; i++)
			printf("  %s\n", current_path->array[i]->name);
	}
	else
	{
		while (connection)
		{
			if (!(connection->to_room->is_visited))
				depth_first_traversal(lem_in, connection->to_room, path_array, current_path);
			connection = connection->next;
		}
	}
	remove_room_from_array(current_path, room);
	room->is_visited = 0;
}

void	find_path(t_lem_in *lem_in)
{
	t_path_array path_array;
	t_room_array current_path;

	init_path_array(&path_array, 10);
	init_room_array(&current_path, 10);

	depth_first_traversal(lem_in, lem_in->start, &path_array, &current_path);

	lem_in->paths = &path_array;

	free_room_array(&current_path);
}
