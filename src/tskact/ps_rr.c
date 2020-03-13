/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:28:42 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 21:32:02 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_rr(t_psab *stacks)
{
	ps_dact(&(stacks->a), &(stacks->b), ft_lstshftup);
	if (stacks->debug)
	{
		ft_putendl("\033[31mAction: rr\033[0m");
		ps_showstcks(stacks);
	}
	else
		ft_putendl("rr");
}
