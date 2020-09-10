/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:20:07 by jkuusist          #+#    #+#             */
/*   Updated: 2020/03/02 15:30:48 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(long num, int base)
{
	char	*s;
	long	n;
	long	i;

	n = num;
	i = 1;
	while ((n /= base) >= 1)
		i++;
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	n = num;
	while (i--)
	{
		s[i] = (n % base < 10) ? (n % base + '0') : (n % base + 'A' - 10);
		n /= base;
	}
	return (s);
}
