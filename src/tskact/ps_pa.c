/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:24:40 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 23:38:48 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_pa(t_psab *stacks)
{
	ft_lsttrans(&(stacks->a), &(stacks->b));
	if (stacks->size_b != 0)
	{
		stacks->size_a++;
		stacks->size_b--;
	}
	if (stacks->debug)
	{
		ft_putendl("\033[31mAction: pa\033[0m");
		ps_showstcks(stacks);
	}
	else
		ft_putendl("pa");
}
