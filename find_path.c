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

void	find_path(t_lem_in *lem_in)
{
	t_room *temp;
	t_room *path;
	t_room *path_start;

	temp = lem_in->start;

	path_start = NULL;	

	while (temp)
	{
		temp->has_ant = 1;
		path = temp;
		if (!path_start)
			path_start = temp;

		while (path->connection)
		{
			if ((path->connection)->to_room == lem_in->end)
			{
				path->next = NULL;
				lem_in->path = path_start;

//				ft_printf("found path to end from %s\n", temp->name);
//				return ;
			}
			path->path_next = (path->connection)->to_room;
			path->connection = (path->connection)->next;
		}
		temp = temp->next;
	}
}
