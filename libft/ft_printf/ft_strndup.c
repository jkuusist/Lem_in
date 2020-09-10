/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 12:00:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/06/10 12:26:30 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(const char *s1, unsigned int n)
{
	unsigned int	len;
	char			*result;

	len = 0;
	while (s1[len] != '\0')
		len++;
	result = (char*)(malloc((len + 1) * sizeof(char)));
	if (!result)
		return (0);
	len = 0;
	while ((s1[len] != '\0') && (len < n))
	{
		result[len] = s1[len];
		len++;
	}
	result[len] = '\0';
	return (result);
}
