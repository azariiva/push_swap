/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:31:34 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 21:33:50 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_rra(t_psab *stacks)
{
	ft_lstshftdown(&(stacks->a));
	if (stacks->debug)
	{
		ft_putendl("\033[31mAction: rra\033[0m");
		ps_showstcks(stacks);
	}
	else
		ft_putendl("rra");
}
