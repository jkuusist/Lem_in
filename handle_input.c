/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:26:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/09/11 11:26:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"
#include "libft/libft.h"
#include <stdlib.h>

void	handle_num_ants(char *s, t_lem_in *lem_in)
{
	int		num_ants;
	int		i;
	t_ant	*temp;

	num_ants = ft_atoi_error(s);
	i = 1;
	
//	lem_in->ant = create_ant(i);
//	temp = lem_in->ant;
//	i++;

	while (i <= num_ants)
	{
//		temp->next = create_ant(i);
//		temp = temp->next;
		
		ft_printf("got into handle_num_ants's while loop\n");

		temp = create_ant(i);
		temp->next = lem_in->ant;
		lem_in->ant = temp;
		i++;
	}
//	ft_printf("lem_in->start is %p\n", lem_in->start);

//	(lem_in->start)->ant = lem_in->ant;

	lem_in->map = create_map_link(s, 0);
	lem_in->map_start = lem_in->map;

}

void	handle_input(t_lem_in *lem_in)
{
	int		ret;
	char	*s;
	int		line_num;
	int		is_start;
	int		is_end;

	ret = 1;
	line_num = 1;
	is_start = 0;
	is_end = 0;
	while (ret == 1)
	{
//		ft_printf("in input loop. lem_in->room is %p\n", lem_in->room);

		ret = get_next_line(0, &s);

		if (ret == 1)
		{
		(lem_in->map)->next = create_map_link(s, line_num);
		lem_in->map = lem_in->map->next;

//		ft_printf("in handle_input. lem_in->map is now %s\n", (lem_in->map)->line);
//		ft_printf("in handle_input. lem_in->map->next is now %s\n", ((lem_in->map)->next)->line);
	
		if (s[0] == '#')
		{
			if (s[1] == '#')
			{
				if (!(ft_strcmp("##start", s)))
				{
					if (lem_in->start)
						handle_error(); //TBI
					is_start = 1;
				}
				else if (!(ft_strcmp("##end", s)))
				{
					if (lem_in->end)
						handle_error(); //TBI
					is_end = 1;
				}
				else
				{
					free(s);
					continue;
				}
			}
			else
			{
				free(s);
				continue;
			}
		}
		else if (ft_strchr(s, '-'))
			handle_link(s, lem_in);
		else if (has_digit(s))
		{
			handle_room(s, lem_in, is_start, is_end);
			is_start = 0;
			is_end = 0;
		}
		
		free(s);
		}
	}
}
