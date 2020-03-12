/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:52:36 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/12 20:31:51 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

char	*ps_atoi(char *str, long long *num)
{
	int	sign;

	sign = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '-')
	{
		sign = 1;
		++str;
	}
	else if (*str == '+' && !ft_isdigit(*++str))
		return (NULL);
	*num = 0;
	while (ft_isdigit(*str))
	{
		*num = *num * 10 + (int)*str++ - '0';
		if ((!sign && *num > INT_MAX) || (sign && *num - 1 > INT_MAX))
			return (NULL);
	}
	if (sign)
		*num = -*num;
	return (str);
}
