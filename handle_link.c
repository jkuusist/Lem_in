/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 10:03:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/09/28 10:03:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"
#include "libft/libft.h"
#include <stdlib.h>

void	handle_link(char *s, t_lem_in *lem_in)
{
	t_link	*new;
	char 	**rooms;
	t_room	*temp;
	t_link	*link_temp;
	int		is_found;	

	if (!(new = (t_link*)malloc(sizeof(t_link))))
		exit(-1);
	rooms = ft_strsplit(s, '-');
	temp = lem_in->room;
	link_temp = lem_in->link;
	is_found = 0;
	if (rooms[2] != NULL)
		handle_error(); //TBI

	//MAYBE IMPLEMENT A HASHMAP FOR FASTER CHECKING OF WHETHER ROOM NAMES EXIST
	while (temp)
	{
		if (!(ft_strcmp(rooms[0], temp->name)))
		{
			new->room_one = temp;
			is_found = 1;
		}
		temp = temp->next;
	}
	if (is_found == 0)
		handle_error(); //TBI
	temp = lem_in->room;
	is_found = 0;
	while (temp)
	{
		if (!(ft_strcmp(rooms[1], temp->name)))
		{
			new->room_two = temp;
			is_found = 1;
		}
		temp = temp->next;
	}
	if (is_found == 0)
		handle_error(); //TBI
	new->next = NULL;
	new->previous = NULL;
	if (!(lem_in->link))
		lem_in->link = new;
	else
	{
		while (link_temp->next)
			link_temp = link_temp->next;
		link_temp->next = new;
	}
	
	free(rooms[0]);
	free(rooms[1]);
	free(rooms[2]);
	free(rooms);
}
