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

void move_ants(t_lem_in *lem_in)
{
	t_path *temp;

	unsigned int used;

	used = lem_in->paths->used;

	for (unsigned int i = 0; i < used; i++)
	{
		printf("in loop. i is %u. used is %u\n", i, used);

		temp = lem_in->paths->array[i];

		printf("path[%u] is:\n", i);

		while (temp)
		{
			printf("  %s\n", temp->room->name);

			temp = temp->next;
		}
	}

	printf("MOVE_ANTS PLACEHOLDER\n");
}
