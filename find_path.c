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
#include "libft/libft.h"
#include <stdlib.h>

static t_room	**create_room_array(t_room **rooms, int room_count)
{
	t_room			**temp;
	t_room			**new;
	t_connection	*path;
	int				i;

	i = 0;
	if (!(new = (t_room**)malloc(sizeof(t_room**) * (room_count + 1))))
		exit(-1);
	temp = rooms;
	while (*temp)
	{
		path = (*temp)->connection;

		while (path)
		{
			if (!((path->to_room)->has_ant))
			{
				new[i] = path->to_room;
				i++;
			}
			path = path->next;
		}
		temp++;
	}
	new[i] = NULL;

	return (new);
}

static int		check_paths(t_lem_in *lem_in, t_room **rooms, t_room **new, int room_count)
{
	t_room			**temp;
	t_connection	*path;

	temp = rooms;
	while (*temp)
	{
		(*temp)->has_ant = 1;
		path = (*temp)->connection;
		while (path)
		{
			room_count++;
			if (path->to_room == lem_in->end)
			{
				(*temp)->path_next = lem_in->end;
				(lem_in->end)->path_previous = *temp;
				lem_in->path = *temp;
				return (1);
			}
			path = path->next;
		}
		temp++;
	}
	if (!room_count || !(new = (create_room_array(rooms, room_count))) || !(check_paths(lem_in, new, NULL, 0)))
	{
		free(new);
		return(0);
	}
	temp = rooms;
	while (*temp)
	{
		path = (*temp)->connection;

//		ft_printf("*temp is %s\n", (*temp)->name);

		while (path)
		{
			if ((path->to_room == lem_in->path) && (path->to_room != *temp))
			{
				(*temp)->path_next = lem_in->path;
				(lem_in->path)->path_previous = *temp;
				lem_in->path = *temp;
			}
			path = path->next;
		}
		temp++;
	}
	free(new);
	return (1);
}

void			find_path(t_lem_in *lem_in)
{
	t_room	**rooms;

	if (!(rooms = (t_room**)malloc(sizeof(t_room*) * 2)))
		exit(-1);
	rooms[0] = lem_in->start;
	rooms[1] = NULL;
 	if (!(check_paths(lem_in, rooms, NULL, 0)))
		handle_error(); //TBI
	free(rooms);
}
