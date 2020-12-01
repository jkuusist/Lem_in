/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:16:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/10/29 10:16:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"
#include "libft/libft.h"
#include <stdlib.h>

t_link			*get_link(t_lem_in *lem_in, t_room *start, t_room *end)
{
	t_link *current;

	current = lem_in->link;
	while (current)
	{
		if (start && (current->room_one == start))
			return (current);
		if (end && (current->room_two == end))
			return (current);
		current = current->next;
	}
	return (NULL);
}

static void		add_link_to_path(t_path *path, t_link *link)
{
	t_link *previous;
	t_link *current;

	previous = NULL;
	current = path->head;
	if (current)
	{
		while (current)
		{
			previous = current;
			current = current->next;
		}
		link->previous = previous;
		previous->next = link;
	}
	else
		path->head = link;
	path->len++;
}

static t_link	*remove_link(t_lem_in *lem_in, t_link *link)
{
	t_link *previous;
	t_link *current;

	previous = NULL;
	current = lem_in->link;

	while (current && (current != link))
	{
		previous = current;
		current = current->next;
	}
	if (!previous && current)
		lem_in->link = current->next;
	else if (current)
		previous->next = current->next;
	link->next = NULL;
	return (link);
}

static void		add_path(t_lem_in *lem_in, t_path *path)
{
	t_path *previous;
	t_path *current;

	previous = NULL;
	current = lem_in->paths;
	if (current)
	{
		while (current && (path->len > current->len))
		{
			previous = current;
			current = current->next;
		}
		if (!previous)
			lem_in->paths = path;
		else
			previous->next = path;
		path->next = current;
	}
	else
		lem_in->paths = path;
}

void			find_path(t_lem_in *lem_in)
{
	t_path *path;
	t_link *link;

	while (lem_in->link)
	{
		path = create_path();
		link = get_link(lem_in, lem_in->start, NULL);


		add_link_to_path(path, remove_link(lem_in, link));
		while (link->room_two != lem_in->end)
		{
			link = get_link(lem_in, link->room_two, NULL);
			add_link_to_path(path, remove_link(lem_in, link));
		}
		add_path(lem_in, path);
	}
}
