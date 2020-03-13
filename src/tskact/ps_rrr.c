/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:32:38 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 21:33:58 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_rrr(t_psab *stacks)
{
	ps_dact(&(stacks->a), &(stacks->b), ft_lstshftdown);
	if (stacks->debug)
	{
		ft_putendl("\033[31mAction: rrr\033[0m");
		ps_showstcks(stacks);
	}
	else
		ft_putendl("rrr");
}
