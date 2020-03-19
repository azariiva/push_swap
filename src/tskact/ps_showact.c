/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_showact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:48:54 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/15 17:13:57 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_showact(char *action, t_psab *stacks)
{
	if (stacks->debug)
	{
		if (stacks->color)
			ft_putstr(RED_FONT);
		ft_putstr("Action: ");
		ft_putendl(action);
		if (stacks->color)
			ft_putstr(RESET_CONSOLE);
		ps_showstcks(stacks);
	}
	else
		ft_putendl(action);
}
