/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:29:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/09/11 11:29:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct	s_lem_in
{
	struct s_map	*map;
	int				num_ants;
	int				num_rooms;
	
}				t_lem_in;

typedef struct	s_map
{
	char			*line;
	int				line_num;
	struct s_map	*next;
}				t_map;

typedef struct	s_room
{
	char	*name;
	int		x_coord;
	int		y_coord;
	int		is_start;
	int		is_end;
}				t_room;

t_lem_in	*create_lem_in(void);
void		destroy_lem_in(t_lem_in *lem_in);
int			handle_input(char *s);
void		handle_num_ants(char *s, t_lem_in *lem_in);

#endif
