/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_illegal_opt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:41:25 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/14 12:46:05 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void			show_illegal_opt(int g_optopt)
{
	ft_printf("checker: illegal option -- %c\n\
	Try \'checker -h\' for more information.", g_optopt);
}
