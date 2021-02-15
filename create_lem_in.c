/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lem_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:25:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/09/16 11:25:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"
#include <stdlib.h>

t_lem_in	*create_lem_in(void)
{
	t_lem_in *new;
	t_path_array new_arr;

	if (!(new = (t_lem_in*)malloc(sizeof(t_lem_in))))
		exit(-1);
	new->map = NULL;
	new->num_rooms = 0;
	new->room = NULL;
	new->start = NULL;
	new->end = NULL;
	new->ant = NULL;

//	new->paths = NULL;
	init_path_array(&new_arr, 5);
	new->paths = &new_arr;

	return (new);
}
