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
	t_room *temp;

	(lem_in->start)->ant = lem_in->ant;

	while (1)
	{
		temp = lem_in->end;

//		ft_printf("temp is %p\n", temp);
//		ft_printf("temp->ant is %p\n", temp->ant);
//		ft_printf("temp->ant is %p. temp->ant->next is %p\n", temp->ant, (temp->ant)->next);
//		return ;

		if (temp->ant && !(temp->ant->next))
			return ;
		while (temp)
		{
			if (temp->path_previous && (temp->path_previous)->ant && !(temp->ant))
			{
				temp->ant = (temp->path_previous)->ant;
				ft_printf("L%d-%s ", (temp->ant)->num, temp->name);
			}
			else if (temp->ant)
			{
				temp->ant = (temp->ant)->next;
				if ((temp != lem_in->start) && temp->ant)
					ft_printf("L%d-%s ", (temp->ant)->num, temp->name);
			}
			temp = temp->path_previous;
		}
		ft_printf("\n");
	}
}
