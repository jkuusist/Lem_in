/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 11:26:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/10/13 11:26:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"
#include "libft/libft.h"

void	move_ants(t_lem_in *lem_in)
{
	t_room *path_temp;

	path_temp = lem_in->start;

	ft_printf("---PATH---\n");

	while (path_temp)
	{
		ft_printf("currently in: %s at: %p\n", path_temp->name, path_temp);
		path_temp = path_temp->path_next;
	}
	ft_printf("after while loop. path_temp is now %p\n", path_temp);


/*
	t_ant *ant_temp;
	t_map *map_temp;
	t_room *temp;
	t_connection *conn_temp;

//	t_link *link_temp;

	ant_temp = lem_in->ant;
	map_temp = lem_in->map_start;
	temp = lem_in->room;
//	link_temp = lem_in->link;
*/
/*
	while (ant_temp)
	{
		ft_printf("in ant number %d\n", ant_temp->num);

		ant_temp = ant_temp->next;
	}

	while (map_temp)
	{
		if (map_temp->line)
			ft_printf("%s\n", map_temp->line);

		map_temp = map_temp->next;
	}

	while (temp)
	{
		ft_printf("in room %s. temp is %p\n", temp->name, temp);

		conn_temp = temp->connection;
		while (conn_temp)
		{
			ft_printf("   Connected to: %s (%p)\n", (conn_temp->to_room)->name, conn_temp->to_room);
			conn_temp = conn_temp->next;
		}

		temp = temp->next;
	}
*/
/*
	while (link_temp)
	{
		ft_printf("in link %s-%s. link_temp is %p\n", (link_temp->room_one)->name, 
		(link_temp->room_two)->name, link_temp);

		ft_printf("room_one is %p. room_two is %p\n", link_temp->room_one, link_temp->room_two);

		link_temp = link_temp->next;
	}
*/
}
