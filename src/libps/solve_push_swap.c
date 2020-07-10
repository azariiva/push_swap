/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:19:27 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/10 19:58:01 by blinnea          ###   ########.fr       */
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

static void	i_love_making_my_code_unreadable(t_push_swap *ps)
{
	if (((t_ps *)ps->a->top->content)->index == ps->a->minimum)
	{
		ps->make_move(ps, "sa");
		ps->make_move(ps, "ra");
	}
	else if (((t_ps *)ps->a->top->content)->index == ps->a->maximum)
		ps->make_move(ps, "ra");
	else if (((t_ps *)ps->a->top->next->content)->index == ps->a->minimum)
		ps->make_move(ps, "sa");
	else
		ps->make_move(ps, "rra");
}

static void	and_you_cant_judge_me(t_push_swap *ps)
{
	int	order;

	if (ps->a->size < 3)
	{
		(ps->a->sorted(ps->a) != ASCENDING ? ps->make_move(ps, "sa") : 0);
		return ;
	}
	if ((order = ps->a->sorted(ps->a)) == DESCENDING)
	{
		ps->make_move(ps, "sa");
		ps->make_move(ps, "rra");
	}
	else if (order == UNSORTED)
		i_love_making_my_code_unreadable(ps);
}

void		solve_push_swap(t_push_swap *ps)
{
	size_t	thrown;

	if (ps->a->size <= 3)
	{
		and_you_cant_judge_me(ps);
		return ;
	}
	if ((thrown = throw_right_median(
		ps, (ps->a->maximum + ps->a->minimum + 1) / 2)) <= 2)
	{
		and_you_cant_judge_me(ps);
		if (((t_ps *)ps->b->top->content)->index == ps->b->minimum &&
		ps->b->top->next)
			ps->make_move(ps, "sb");
		(ps->b->top ? ps->make_move(ps, "pa") : 0);
		(ps->b->top ? ps->make_move(ps, "pa") : 0);
		return ;
	}
	push_swap(ps);
	throw_right(ps, ps->a->size - thrown);
	push_swap(ps);
}
