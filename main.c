/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 11:39:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/09/10 11:58:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"
#include "libft/libft.h"
#include <stdlib.h>

#include <stdio.h>

int main(/*int argc, char **argv*/)
{

	int ret;
	char	*s;
	t_lem_in *lem_in;
	t_map	*temp;
	int		num_ants;

	lem_in = create_lem_in();

	ret = get_next_line(0, &s);

	if (ret == -1)
		return (-1);

	//FIRST INPUT IS ALWAYS THE NUMBER OF ANTS
	num_ants = handle_num_ants(s, lem_in);

	free(s);

	handle_input(lem_in, num_ants);

	temp = lem_in->map_start;
	while (temp)
	{
		ft_printf("%s\n", temp->line);
		temp = temp->next;
	}
	ft_printf("\n");

	make_connections(lem_in);

	find_path(lem_in);

	move_ants(lem_in);

	destroy_lem_in(lem_in);

	return (0);
}
