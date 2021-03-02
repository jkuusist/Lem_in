/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_array_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 08:53:00 by jkuusist          #+#    #+#             */
/*   Updated: 2021/02/02 08:53:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"
#include "libft/libft.h"
#include <stdlib.h>

void	init_room_array(t_room_array *arr, unsigned int size)
{
	arr->array = (t_room**)malloc(sizeof(t_room*) * size);
	ft_bzero(arr->array, size);
	arr->used = 0;
	arr->size = size;
}

void	insert_room_into_array(t_room_array *arr, t_room *room)
{
	if (room)
	{
		if (arr->used == arr->size)
		{
			arr->size *= 2;

			arr->array = realloc(arr->array, (sizeof(t_room*) * arr->size));
		}
		arr->array[arr->used] = room;
		arr->used++;
	}
}

void	remove_room_from_array(t_room_array *arr, t_room *room)
{
	unsigned int i;

	i = 0;
	while (i < arr->used)
	{
		if (arr->array[i] == room)
			break;
		i++;
	}
	while (i < arr->size - 1)
	{
		arr->array[i] = arr->array[i + 1];
		i++;
	}
	arr->used--;
}

void	free_room_array(t_room_array *arr)
{
	free(arr->array);
	arr->array = NULL;
	arr->used = 0;
	arr->size = 0;
}
