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

	ret = get_next_line(0, &s);

	//FIRST INPUT IS ALWAYS THE NUMBER OF ANTS
	handle_num_ants(s); //TBI

	free(s);

	while (ret != 0)
	{
		ret = get_next_line(0, &s);
		if (ret == 1)
		{
			if (!handle_input(s))
			{
				//PROBABLY WANT TO FREE EXISTING ROOMS HERE AS WELL

				free(s);
				ft_printf("ERROR\n");
				return (-1);
			}
		}
		else
		{
			free(s);
			return (0);
		}
		free(s);
	}

	return (0);	
}
