/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:24:40 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/15 17:12:28 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_pa(t_psab *stacks)
{
	ft_lsttrans(&(stacks->a), &(stacks->b));
	ps_showact("pa", stacks);
	if (stacks->size_b)
	{
		stacks->size_a++;
		stacks->size_b--;
	}
}
