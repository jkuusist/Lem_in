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
	struct s_map	*map_start;
	int				num_rooms;
	struct s_room	*room;
	struct s_link	*link;
	struct s_room	*start;
	struct s_room	*end;
	struct s_ant	*ant;
}				t_lem_in;

typedef struct	s_map
{
	char			*line;
	int				line_num;
	struct s_map	*next;
}				t_map;

typedef struct	s_room
{
	char				*name;
	int					x_coord;
	int					y_coord;
	int					is_start;
	int					is_end;
	int					has_ant;
	struct s_connection	*connection;
	struct s_room		*next;
}				t_room;

typedef struct	s_link
{
	struct s_room	*room_one;
	struct s_room	*room_two;
	struct s_link	*next;
	
}				t_link;

typedef struct	s_ant
{
	int				num;
	struct s_ant	*next;
}				t_ant;

typedef struct	s_connection
{
	t_room 				*to_room;
	struct s_connection	*next;
}				t_connection;

t_lem_in	*create_lem_in(void);
void		destroy_lem_in(t_lem_in *lem_in);
void		handle_input(t_lem_in *lem_in);
void		handle_num_ants(char *s, t_lem_in *lem_in);
t_map		*create_map_link(char *s, int line_num);
long long	ft_atoi_error(const char *str);
void		handle_error();
void		handle_link(char *s, t_lem_in *lem_in);
void		handle_room(char *s, t_lem_in *lem_in, int is_start, int is_end);
int			has_digit(char *s);
void		move_ants(t_lem_in *lem_in);
t_ant		*create_ant(int num);
void		make_connections(t_lem_in *lem_in);
void		find_path(t_lem_in *lem_in);

#endif
