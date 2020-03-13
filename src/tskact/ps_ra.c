/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:28:44 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 21:33:40 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_ra(t_psab *stacks)
{
	ft_lstshftup(&(stacks->a));
	if (stacks->debug)
	{
		ft_putendl("\033[31mAction: ra\033[0m");
		ps_showstcks(stacks);
	}
	else
		ft_putendl("ra");
}
