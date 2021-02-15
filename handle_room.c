/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:00:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/09/18 10:00:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"
#include "libft/libft.h"
#include <stdlib.h>

void	handle_room(char *s, t_lem_in *lem_in, int is_start, int is_end, int num_ants)
{
	t_room	*new;
	char	*s_start;
	t_room	*temp;

	s_start = s;
	temp = lem_in->room;
	if (!(new = (t_room*)malloc(sizeof(t_room))))
		exit (-1);
	if ((s[0] == 'L') || (s[0] == '#'))
		handle_error(); //TBI
	while (*s)
		s++;
	s--;
	while (ft_isdigit(*s))
		s--;
	new->y_coord = ft_atoi(s);
	s--;
	while (ft_isdigit(*s))
		s--;
	new->x_coord = ft_atoi(s);
	new->name = ft_strndup(s_start, (s - s_start));
	new->is_start = 0;
	new->is_end = 0;
	new->is_visited = 0;
	new->connection = NULL;
	new->next = NULL;
	new->path_next = NULL;
	new->path_previous = NULL;
	new->ant = NULL;
	new->in_path = 0;
	if (is_start)
	{
		lem_in->start = new;
		new->is_start = 1;
		new->ants_here = num_ants;
	}
	else if (is_end)
	{
		lem_in->end = new;
		new->is_end = 1;
	}
	if (!(lem_in->room))
		lem_in->room = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
