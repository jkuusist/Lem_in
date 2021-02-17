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
	get_path_lengths(lem_in);

	for (unsigned int i = 0; i < lem_in->paths->used; i++)
	{
		printf("path[%u]->len is %u\n", i, lem_in->paths->array[i]->len);

	}

	printf("lem_in->paths->size is now %u. lem_in->paths->used is now %u\n", lem_in->paths->size, lem_in->paths->used);

	printf("MOVE_ANTS PLACEHOLDER\n");
}
