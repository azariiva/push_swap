/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_if_step.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:47:20 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/14 12:48:59 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <unistd.h>
#include <stdlib.h>

void	clear_if_step(t_push_swap *ps)
{
	if (ps->step)
	{
		usleep(200000);
		system("clear");
	}
}
