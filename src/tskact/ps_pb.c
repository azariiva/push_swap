/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:28:07 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 23:38:29 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_pb(t_psab *stacks)
{
	ft_lsttrans(&(stacks->b), &(stacks->a));
	if (stacks->size_a != 0)
	{
		stacks->size_a--;
		stacks->size_b++;
	}
	if (stacks->debug)
	{
		ft_putendl("\033[31mAction: pb\033[0m");
		ps_showstcks(stacks);
	}
	else
		ft_putendl("pb");
}
