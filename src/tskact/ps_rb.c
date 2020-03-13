/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:28:47 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 21:33:43 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_rb(t_psab *stacks)
{
	ft_lstshftup(&(stacks->b));
	if (stacks->debug)
	{
		ft_putendl("\033[31mAction: rb\033[0m");
		ps_showstcks(stacks);
	}
	else
		ft_putendl("rb");
}
