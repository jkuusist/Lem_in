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

void	move_ants(t_lem_in *lem_in)
{
	//temporary solution
	//full functionality TBI

//	int i = 0;

	t_room *temp;

	temp = lem_in->room;

	while (temp)
	{
		ft_printf("in room %s. temp is %p\n", temp->name, temp);

		temp = temp->next;
	}
/*
	while (i < lem_in->num_ants)
	{
		ft_printf("moving ant #%d\n", i);
		i++;
	}
*/
//	ft_printf("got to end of move_ants\n");
}
