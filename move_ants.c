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
#include <stdlib.h>

static void	free_location(t_location *loc)
{
	t_location *temp;

	while (loc)
	{
		temp = loc;
		loc = loc->next;
		free(temp);
	}
}

static void add_loc(t_lem_in *lem_in, t_room *room, int ant_num)
{
	t_location *loc;
	t_location *previous;
	t_location *current;

	if (!(loc = (t_location*)malloc(sizeof(t_location))))
		exit(-1);
	loc->ant_num = ant_num;
	loc->room = room;
	loc->next = NULL;

	previous = NULL;
	current = lem_in->location;

	if (current)
	{
		while (current && loc->ant_num > current->ant_num)
		{
			previous = current;
			current = current->next;
		}
		if (!previous)
		{
			lem_in->location = loc;
		}
		else
			previous->next = loc;
		loc->next = current;
	}
	else
		lem_in->location = loc;
}

static void move_along_path(t_lem_in *lem_in, t_path *path)
{
	t_link *current;

	current = path->head;
	while (current->next)
		current = current->next;
	while (current)
	{
		if (((current->room_one)->ant_num != -1) && (current->room_two == lem_in->end))
		{
			add_loc(lem_in, current->room_two, (current->room_one)->ant_num);
			(current->room_one)->ants_here = -1;
			(lem_in->end)->ants_here++;
		}
		else if ((current->room_one)->ant_num != -1)
		{
			add_loc(lem_in, current->room_two, (current->room_one)->ant_num);
			(current->room_two)->ant_num = (current->room_one)->ant_num;
			(current->room_one)->ant_num = -1;
		}
		current = current->previous;
	}
}

static void move_from_start(t_lem_in *lem_in, t_path *path)
{
	if ((path->head)->room_two == lem_in->end)
	{
		(lem_in->start)->ants_here--;
		(lem_in->end)->ants_here++;
		add_loc(lem_in, (path->head)->room_two, ++(lem_in->ant_num));
	}
	else
	{
		(lem_in->start)->ants_here--;
		((path->head)->room_two)->ant_num = ++(lem_in->ant_num);
		add_loc(lem_in, (path->head)->room_two, ((path->head)->room_two)->ant_num);
	}
}

static int	length_difference(t_lem_in *lem_in, t_path *path)
{
	int		res;
	t_path	*current;

	res = 0;
	current = lem_in->paths;
	while (current != path)
	{
		res += (path->len) - (current->len);
		current = current->next;
	}
	return (res);
}

void	move_ants(t_lem_in *lem_in)
{
	ft_printf("1\n");

	t_path *current;
	t_location *loc;

	ft_printf("start->ants is %d. end->ants is %d\n", (lem_in->start)->ants_here, (lem_in->end)->ants_here);

	while((lem_in->start)->ants_here || (lem_in->ant_num != (lem_in->end)->ants_here))
	{
		current = lem_in->paths;
		while (current)
		{
			move_along_path(lem_in, current);
			current = current->next;
		}

		ft_printf("2\n");

		current = lem_in->paths;
		while (current && (lem_in->start)->ants_here)
		{
			if ((lem_in->start)->ants_here > length_difference(lem_in, current))
				move_from_start(lem_in, current);
			current = current->next;
		}
		
		loc = lem_in->location;
		while (loc)
		{
			if (loc != lem_in->location)
				ft_printf(" ");
			ft_printf("L%d-%s", loc->ant_num, (loc->room)->name);
			loc = loc->next;
		}
		ft_printf("\n");
		
		ft_printf("3\n");

		free_location(lem_in->location);
		lem_in->location = NULL;
	}
	ft_printf("4\n");
}
