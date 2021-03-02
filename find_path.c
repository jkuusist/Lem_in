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

void depth_first_traversal(t_lem_in *lem_in, t_room *room, t_path_array *path_array, t_room_array *current_path)
{
	t_connection	*connection;
	t_path			*new_path;
	t_path			*new_path_start;
	t_path			*path_next;

	connection = room->connection;

	insert_room_into_array(current_path, room);
	room->is_visited = 1;

	if (room->is_end)
	{
		new_path = create_path();

		new_path->room = current_path->array[0];

		new_path_start = new_path;

		for (unsigned int i = 1; i < current_path->used; i++)
		{
			path_next = create_path();
			path_next->room = current_path->array[i];

			while (new_path->next)
				new_path = new_path->next;

			new_path->next = path_next;
		}

		insert_path_into_array(path_array, new_path_start);
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
	t_path_array *path_array;
	t_room_array current_path;

	path_array = init_path_array(10);
	init_room_array(&current_path, 10);
	depth_first_traversal(lem_in, lem_in->start, path_array, &current_path);
	lem_in->paths = path_array;
	free_room_array(&current_path);
	if (path_array->used == 0)
		handle_error(lem_in);
}
