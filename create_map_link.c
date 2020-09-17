/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 11:04:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/09/17 11:04:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_map *create_map_link(char *s, int line_num)
{
	t_map *new;

	if (!(new = (t_map*)malloc(sizeof(t_map))))
		exit(-1);
	new->line = s;
	new->line_num = line_num;
	new->next = NULL;
}
