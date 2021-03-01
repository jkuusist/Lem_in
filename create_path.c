/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:33:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/11/30 11:33:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"
#include <stdlib.h>

t_path	*create_path()
{
	t_path *new;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		exit(-1);
	new->room = NULL;
	new->len = 0;
	new->ants_in_path = 0;
	new->next = NULL;

	return (new);
}
