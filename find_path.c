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
	t_connection *path;

	temp = lem_in->start;
	
	while (temp)
	{
		temp->has_ant = 1;
		path = temp->connection;

		while (path)
		{
			if (path->to_room == lem_in->end)
			{
				ft_printf("found path to end from %s\n", temp->name);
//				return ;
			}
			path = path->next;
		}
		temp = temp->next;
	}
}
