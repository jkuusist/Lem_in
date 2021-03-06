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

typedef struct	s_room
{
	char				*name;
	int					x_coord;
	int					y_coord;
	int					is_start;
	int					is_end;
	int					is_visited;
	struct s_connection	*connection;
	struct s_ant		*ant;
	unsigned int		ants_here;
	int					ant_num;
	struct s_room		*next;
}				t_room;

typedef struct	s_room_array
{
	t_room			**array;
	unsigned int	used;
	unsigned int	size;
}				t_room_array;

typedef struct	s_path
{
	t_room			*room;
	unsigned int	len;
	unsigned int	ants_in_path;
	struct s_path	*next;
}				t_path;

typedef struct	s_path_array
{
	t_path			**array;
	unsigned int	used;
	unsigned int	size;
}				t_path_array;

typedef struct	s_lem_in
{
	struct s_map		*map;
	struct s_map		*map_start;
	struct s_room		*room;
	struct s_link		*link;
	struct s_room		*start;
	struct s_room		*end;
	struct s_ant		*ant;
	struct s_path_array	*paths;
	struct s_location	*location;
	unsigned int		num_ants;
}				t_lem_in;

typedef struct	s_map
{
	char			*line;
	int				line_num;
	struct s_map	*next;
}				t_map;

typedef struct	s_link
{
	struct s_room	*room_one;
	struct s_room	*room_two;
	struct s_link	*next;
}				t_link;

typedef struct	s_ant
{
	int				num;
	t_path			*path;
	struct s_ant	*next;
}				t_ant;

typedef struct	s_connection
{
	t_room 				*to_room;
	struct s_connection	*next;
}				t_connection;

t_lem_in		*create_lem_in(void);
void			destroy_lem_in(t_lem_in *lem_in);
void			handle_input(t_lem_in *lem_in);
int				handle_num_ants(char *s, t_lem_in *lem_in);
t_map			*create_map_link(char *s, int line_num);
long long		ft_atoi_error(const char *str, t_lem_in *lem_in);
void			handle_error(t_lem_in *lem_in);
void			handle_link(char *s, t_lem_in *lem_in);
void			handle_room(char *s, t_lem_in *lem_in, int is_start, int is_end, int num_ants);
int				has_digit(char *s);
void			move_ants(t_lem_in *lem_in);
t_ant			*create_ant(int num);
void			make_connections(t_lem_in *lem_in);
void			find_path(t_lem_in *lem_in);
t_path			*create_path();
void			init_room_array(t_room_array *arr, unsigned int size);
void			insert_room_into_array(t_room_array *arr, t_room *room);
void			free_room_array(t_room_array *arr);
void			remove_room_from_array(t_room_array *arr, t_room *room);
t_path_array	*init_path_array(unsigned int size);
void			insert_path_into_array(t_path_array *arr, t_path *room);
void			free_path_array(t_path_array *arr);
void			sort_paths(t_path **paths, int low, int high);
void			add_ants_to_start(t_lem_in *lem_in);

#endif
