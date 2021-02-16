/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_num_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:56:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/11/24 10:56:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

#include <stdio.h>

int	handle_num_ants(char *s, t_lem_in *lem_in)
{
	int		num_ants;
	int		i;
	t_ant	*temp;

	num_ants = ft_atoi_error(s);
	i = 1;
	while (i <= num_ants)
	{
		temp = create_ant(i);
		temp->next = lem_in->ant;
		lem_in->ant = temp;
		i++;
	}
	lem_in->map = create_map_link(s, 0);
	lem_in->map_start = lem_in->map;

	return (num_ants);
}
