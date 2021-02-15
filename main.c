/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 11:39:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/09/10 11:58:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"
#include "libft/libft.h"
#include <stdlib.h>

#include <stdio.h>

int main(/*int argc, char **argv*/)
{

	int ret;
	char	*s;
	t_lem_in *lem_in;
	t_map	*temp;
	int		num_ants;

	lem_in = create_lem_in();

	ret = get_next_line(0, &s);

	if (ret == -1)
		return (-1);

	//FIRST INPUT IS ALWAYS THE NUMBER OF ANTS
	num_ants = handle_num_ants(s, lem_in);

	free(s);

	handle_input(lem_in, num_ants);

	temp = lem_in->map_start;
	while (temp)
	{
		ft_printf("%s\n", temp->line);
		temp = temp->next;
	}
	ft_printf("\n");

	make_connections(lem_in);

	find_path(lem_in);

	move_ants(lem_in);

	destroy_lem_in(lem_in);
	return (0);
/*
	t_room *temproom = lem_in->room;
	while (temproom)
	{
		t_connection *tempcon = temproom->connection;
		ft_printf("%s connections: \n", temproom->name);
		while (tempcon)
		{
			ft_printf("    %s\n", tempcon->to_room->name);
			tempcon = tempcon->next;
		}
		temproom = temproom->next;
		ft_printf("\n");
	}
*/

/*
	t_path *temppath = lem_in->paths;
	while (temppath)
	{
		ft_printf("temppath is now %p\n", temppath);

		t_link *headtemp = temppath->head;
		while (headtemp)
		{
			ft_printf("temppath->head is now %s-%s\n", temppath->head->room_one->name, temppath->head->room_two->name);
			headtemp = headtemp->next;
		}

		temppath = temppath->next;
	}
*/



/*

	t_room_array room_arr;
	t_room *room;

	room = (t_room*)malloc(sizeof(t_room));

	room->name = "X";
	init_room_array(&room_arr, 5);

	printf("room_arr->used is %d. room_arr->size is %d\n", room_arr.used, room_arr.size);

	insert_room_into_array(&room_arr, room);

	printf("room_arr->used is %d. room_arr->size is %d\n", room_arr.used, room_arr.size);

//	for (unsigned int i = 0; i < room_arr.used; i++)
		printf("  room_arr[%d] is %s\n", 0, room_arr.array[0]->name);

	for (int i = 0; i < 20; i++)
	{
		insert_room_into_array(&room_arr, room);
	}

	printf("now room_arr->used is %d. room_arr->size is %d\n", room_arr.used, room_arr.size);
	for (unsigned int i = 0; i < room_arr.used; i++)
		printf("  room_arr[%d] is %s\n", i, room_arr.array[i]->name);
*/
}
