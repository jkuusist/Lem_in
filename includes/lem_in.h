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
	struct s_room	*room;
	struct s_link	*link;
}				t_lem_in;

typedef struct	s_map
{
	char			*line;
	int				line_num;
	struct s_map	*next;
}				t_map;

typedef struct	s_room
{
	char			*name;
	int				x_coord;
	int				y_coord;
	int				is_start;
	int				is_end;
	struct s_room	*next;
}				t_room;

typedef struct	s_link
{
	struct s_room	room_one;
	struct s_room	room_two;
	struct s_link	next;
	
}				t_link;

t_lem_in	*create_lem_in(void);
void		destroy_lem_in(t_lem_in *lem_in);
int			handle_input(char *s);
void		handle_num_ants(char *s, t_lem_in *lem_in);

#endif
