/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:28:07 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/15 17:12:47 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_pb(t_psab *stacks)
{
	ft_lsttrans(&(stacks->b), &(stacks->a));
	ps_showact("pb", stacks);
	if (stacks->size_a)
	{
		stacks->size_b++;
		stacks->size_a--;
	}
}
