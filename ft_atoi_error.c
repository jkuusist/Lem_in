/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:47:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/09/16 11:47:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_whitespace(char c)
{
	if ((c == ' ') || (c == '\t'))
		return (1);
	if ((c == '\n') || (c == '\v') || (c == '\f') || (c == '\r'))
		return (1);
	else
		return (0);
}

long long	ft_atoi_atoi(const char *str)
{
	int					i;
	unsigned long long	res;

	i = 0;
	res = 0;
	while (is_whitespace(str[i]))
		i++;
	while (str[i]) //(((str[i] >= '0') && (str[i] <= '9')))
	{
		if (!(((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '\0')))
			handle_error(); //TBI
		res = res * 10 + ((unsigned long long)(str[i] - '0'));
		i++;
	}
	return (res);
}
