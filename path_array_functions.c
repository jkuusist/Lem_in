/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_array_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:38:00 by jkuusist          #+#    #+#             */
/*   Updated: 2021/02/02 10:38:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"
#include "libft/libft.h"
#include <stdlib.h>

#include <stdio.h>

t_path_array	*init_path_array(/*t_path_array *arr,*/ unsigned int size)
{
	t_path_array *new;

	new = (t_path_array*)malloc(sizeof(t_path_array));
	new->array = (t_path**)malloc(sizeof(t_path*) * size);
	ft_bzero(new->array, size);
	new->used = 0;
	new->size = size;

	return (new);
}

void	insert_path_into_array(t_path_array *arr, t_path *path)
{
	if (arr->used == arr->size)
	{
		arr->size *= 2;
		arr->array = realloc(arr->array, (sizeof(t_path*) * arr->size));

	}

	arr->array[arr->used] = path;
	arr->used++;
}

void	free_path_array(t_path_array *arr)
{
	t_path *temp;
	t_path *next;

	for (unsigned int i = 0; i < arr->used; i++)
	{
		temp = arr->array[i];
		while (temp)
		{
			next = temp->next;
			free(temp);
			temp = next;
		}
	}
	free(arr->array);
	arr->array = NULL;
	arr->used = 0;
	arr->size = 0;
	free(arr);
}
