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

#include <stdio.h>

static void	get_path_lengths(t_lem_in *lem_in)
{
	t_path *temp;

	unsigned int used;

	used = lem_in->paths->used;

	for (unsigned int i = 0; i < used; i++)
	{

		temp = lem_in->paths->array[i];

		while (temp)
		{
			lem_in->paths->array[i]->len++;			

			temp = temp->next;
		}
	}
}

static void	assign_ant_paths(t_lem_in *lem_in)
{
	t_ant			*ant_start;
	unsigned int	path_index;

	ant_start = lem_in->ant;

	while (ant_start)
	{
		if (lem_in->paths->used == 1)
			ant_start->path = lem_in->paths->array[0];
		else
		{
			path_index = 0;

			while ((path_index < (lem_in->paths->used - 1)) &&
				((lem_in->paths->array[path_index]->len +
				lem_in->paths->array[path_index]->ants_in_path) >
				lem_in->paths->array[path_index + 1]->len))
			{
				path_index++;
			}

			ant_start->path = lem_in->paths->array[path_index];

			lem_in->paths->array[path_index]->ants_in_path++;
		}

		ant_start = ant_start->next;
	}
}

void move_ants(t_lem_in *lem_in)
{
	t_ant			*ant_start;

	ant_start = lem_in->ant;

	get_path_lengths(lem_in);

	if (lem_in->paths->used > 1)
		sort_paths(lem_in->paths->array, 0, (lem_in->paths->used - 1));

	assign_ant_paths(lem_in);

	while (lem_in->end->ants_here != lem_in->num_ants)
	{
		ant_start = lem_in->ant;

		while (ant_start)
		{
			if (ant_start->path->next && (ant_start->path->next->room == lem_in->end || ant_start->path->next->room->ants_here == 0))
			{
				printf("L%u-%s ", ant_start->num, ant_start->path->next->room->name);

				ant_start->path->room->ants_here = 0;
				ant_start->path->next->room->ants_here++;

				ant_start->path = ant_start->path->next;
			}

			ant_start = ant_start->next;
		}

		printf("\n");
	}
}
