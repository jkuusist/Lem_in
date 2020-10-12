/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_num_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:11:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/10/12 11:11:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	handle_num_ants(char *s, t_lem_in lem_in)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!(ft_isdigit(s[i])))
			return (-1);
		i++;
	}
	lem_in->num_ants = ft_atoi(s);
	return (0);
}
