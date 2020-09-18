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

#include <stdlib.h>

void	handle_room(char *s)
{
	t_room	*new;
	char	*s_start;

	s_start = s;
	if !(new = (t_room*)malloc(sizeof(t_room)))
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
}
