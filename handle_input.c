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

void	handle_num_ants(char *s, t_lem_in *lem_in)
{
	lem_in->num_ants = ft_atoi_error(s);
	lem_in->map = create_map_link(s, 0);
	lem_in->map = lem_in->map->next;
}

void	handle_input(t_lem_in *lem_in)
{
	int		ret;
	char	*s;
	int		line_num;

	ret = 1;
	line_num = 1;
	while (ret == 1)
	{
		ret = get_next_line(0, &s);
		lem_in->map = create_map_link(s, line_num);
		lem_in->map = lem_in->map->next;
		
		if (s[0] == '#')
		{
			if (s[1] == '#')
				handle_modifier(); //TBI
			else
				handle_comment(); //TBI
		}
		else if (ft_strchr(s, '-'))
			handle_link(); //TBI
		else if (has_digit(s))
			handle_room(s); //TBI


		free(s);
	}
}
