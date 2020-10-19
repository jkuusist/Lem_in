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
	//temporary solution
	//full functionality TBI

//	int i = 0;

	t_map *map_temp;
	t_room *temp;
//	t_link *link_temp;

	map_temp = lem_in->map_start;
	temp = lem_in->room;
//	link_temp = lem_in->link;

	while (map_temp)
	{
		ft_printf("%s\n", map_temp->line);

		map_temp = map_temp->next;
	}

	while (temp)
	{
		ft_printf("in room %s. temp is %p\n", temp->name, temp);

		temp = temp->next;
	}

/*
	while (link_temp)
	{
		ft_printf("in link %s-%s. link_temp is %p\n", (link_temp->room_one)->name, 
		(link_temp->room_two)->name, link_temp);

		ft_printf("room_one is %p. room_two is %p\n", link_temp->room_one, link_temp->room_two);

		link_temp = link_temp->next;
	}
*/
/*
	while (i < lem_in->num_ants)
	{
		ft_printf("moving ant #%d\n", i);
		i++;
	}
*/
//	ft_printf("got to end of move_ants\n");
}
