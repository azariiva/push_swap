/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:19:27 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/14 13:48:27 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

static void	push_swap(t_push_swap *ps)
{
	size_t	thrown;

	if (ps->b->size <= 13)
	{
		throw_left_sorted(ps);
		return ;
	}
	thrown = throw_left_median(ps, (ps->b->maximum + ps->b->minimum + 1) / 2);
	push_swap(ps);
	if (thrown)
	{
		throw_right(ps, thrown);
		push_swap(ps);
	}
}

void		solve_push_swap(t_push_swap *ps)
{
	size_t	thrown;

	thrown = throw_right_median(ps, (ps->a->maximum + ps->a->minimum + 1) / 2);
	push_swap(ps);
	throw_right(ps, ps->a->size - thrown);
	push_swap(ps);
}
