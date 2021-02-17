/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_array_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:40:00 by jkuusist          #+#    #+#             */
/*   Updated: 2021/02/17 10:40:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

#include <stdio.h>

static void				swap(t_path **paths, unsigned int i, unsigned int j)
{
	t_path *temp;

	temp = paths[i];
	paths[i] = paths[j];
	paths[j] = temp;
}

static unsigned int		partition(t_path **paths, int low, int high)
{
	t_path	*pivot;
	int		i;

	pivot = paths[high];

	i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (paths[j]->len < pivot->len)
		{
			i++;

			swap(paths, i, j);
		}
	}
	swap(paths, (i + 1), high);

	return (i + 1);
}

void					sort_paths(t_path **paths, int low, int high)
{
	unsigned int part_index;

	if (low < high)
	{
		part_index = partition(paths, low, high);
		sort_paths(paths, low, (part_index - 1));
		sort_paths(paths, (part_index + 1), high);
	}
}
