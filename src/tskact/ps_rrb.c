/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:32:22 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 21:33:54 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_rrb(t_psab *stacks)
{
	ft_lstshftdown(&(stacks->b));
	if (stacks->debug)
	{
		ft_putendl("\033[31mAction: rrb\033[0m");
		ps_showstcks(stacks);
	}
	else
		ft_putendl("rrb");
}
