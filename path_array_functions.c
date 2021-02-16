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

void	init_path_array(t_path_array *arr, unsigned int size)
{
	arr->array = (t_path**)malloc(sizeof(t_path*) * size);
	ft_bzero(arr->array, size);
	arr->used = 0;
	arr->size = size;
}

void	insert_path_into_array(t_path_array *arr, t_path *path)
{
	if (arr->used == arr->size)
	{
		printf("ARRAY FULL\n");

		arr->size *= 2;
		arr->array = realloc(arr->array, (sizeof(t_path*) * arr->size));

	}

	arr->array[arr->used] = path;
	arr->used++;
}

void	free_path_array(t_path_array *arr)
{
	free(arr->array);
	arr->array = NULL;
	arr->used = 0;
	arr->size = 0;
}
