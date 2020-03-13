/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:23:36 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 21:33:12 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_ss(t_psab *stacks)
{
	ps_dact(&(stacks->a), &(stacks->b), ft_lstswptop);
	if (stacks->debug)
	{
		ft_putendl("\033[31mAction: ss\033[0m");
		ps_showstcks(stacks);
	}
	else
		ft_putendl("ss");
}
