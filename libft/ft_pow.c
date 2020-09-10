/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:03:36 by jkuusist          #+#    #+#             */
/*   Updated: 2020/03/04 15:08:15 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long		ft_pow(int base, unsigned int exp)
{
	unsigned int	i;
	long			res;

	i = 0;
	res = 1;
	while (i < exp)
	{
		res *= base;
		i++;
	}
	return (res);
}
