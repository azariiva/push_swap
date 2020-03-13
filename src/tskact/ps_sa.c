/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:57:03 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 21:33:09 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_sa(t_psab *stacks)
{
	ft_lstswptop(&(stacks->a));
	if (stacks->debug)
	{
		ft_putendl("\033[31mAction: sa\033[0m");
		ps_showstcks(stacks);
	}
	else
		ft_putendl("sa");
}
