/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:01:17 by jkuusist          #+#    #+#             */
/*   Updated: 2020/02/13 13:26:01 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function reverses the string given to it. It does this by using a
** bitwise XOR trick I found in the Standford bit twiddling hacks guide.
*/

void	ft_strrev(char *str, int len)
{
	int		i;
	int		j;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		str[i] ^= str[j];
		str[j] ^= str[i];
		str[i] ^= str[j];
		i++;
		j--;
	}
}
