/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 11:35:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/09/17 11:35:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		has_digit(char *s)
{
	while (*s)
	{
		if (ft_isdigit(*s))
			return (1);
		s++;
	}
	return (0);
}
