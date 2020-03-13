/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:22:51 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 21:33:17 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_sb(t_psab *stacks)
{
	ft_lstswptop(&(stacks->b));
	if (stacks->debug)
	{
		ft_putendl("\033[31mAction: sb\033[0m");
		ps_showstcks(stacks);
	}
	else
		ft_putendl("sb");
}
