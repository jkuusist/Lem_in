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

void move_ants(t_lem_in *lem_in)
{
//	int path_index;

//	path_index = 0;

	get_path_lengths(lem_in);

	if (lem_in->paths->used > 1)
		sort_paths(lem_in->paths->array, 0, (lem_in->paths->used - 1));

//	printf("end->ants_here is %u. num_ants is %u\n", lem_in->end->ants_here, lem_in->num_ants);
	printf("first ant is %d\n", lem_in->ant->num);

	//send first ant to first room in shortest path
	lem_in->ant->location = lem_in->paths->array[0]->room;

	ft_printf("L%d-%s \n", lem_in->ant->num, lem_in->paths->array[0]->room->name); //REMEMBER THAT ONE LINE CAN HAVE MULTIPLE MOVES

	lem_in->paths->array[0]->ants_in_path++;
	lem_in->start->ants_here--;
	lem_in->ant = lem_in->ant->next;

/*
	while (lem_in->end->ants_here != lem_in->num_ants)
	{
		if (lem_in->start->ants_here)
		{
			while (lem_in->paths->array[path_index]->ants_in_path)
				path_index++;
			if ((lem_in->paths->array[path_index - 1]->len +
				lem_in->paths->array[path_index - 1]->len) >
				lem_in->paths->array[path_index]->len)
			{
				
			}
		}	
	}
*/
}
