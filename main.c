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

int main(/*int argc, char **argv*/)
{
	int 	ret;
	char	*s;
	t_lem_in *lem_in;

	lem_in = create_lem_in();

	ret = get_next_line(0, &s);

	//FIRST INPUT IS ALWAYS THE NUMBER OF ANTS
	handle_num_ants(s);

	free(s);

	handle_input(lem_in);

	return (0);	
}
