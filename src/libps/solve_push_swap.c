/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:19:27 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/13 10:40:32 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdio.h>

size_t	throw_right_median(t_push_swap *ps, size_t median)
{
	size_t	thrown;

	thrown = 0;
	while (ps->a->minimum != median)
	{
		if (((t_ps *)ps->a->top->content)->index < median)
		{
			ps->make_move(ps, "pb");
			thrown++;
		}
		else
			ps->make_move(ps, "ra");
	}
	return (thrown);
}

size_t	throw_left_median(t_push_swap *ps, size_t median)
{
	size_t	thrown;

	thrown = 0;
	if (ps->b->size / 2 < 13)
		median = ps->b->minimum + 12;
	while (ps->b->maximum != median)
	{
		if (((t_ps *)ps->b->top->content)->index > median)
		{
			ps->make_move(ps, "pa");
			thrown++;
		}
		else if (((t_ps *)ps->b->top->content)->index == ps->b->minimum)
		{
			ps->make_move(ps, "pa");
			ps->make_move(ps, "ra");
			ps->sorted++;
		}
		else
			ps->make_move(ps, "rb");
	}
	return (thrown);
}

void	throw_left_sorted(t_push_swap *ps)
{
	size_t	ontop;

	ontop = 0;
	while (ps->b->size)
	{
		if (((t_ps *)ps->b->top->content)->index == ps->b->maximum)
		{
			ps->make_move(ps, "pa");
			ontop++;
		}
		else if (((t_ps *)ps->b->top->content)->index == ps->b->minimum)
		{
			ps->make_move(ps, "pa");
			ps->make_move(ps, "ra");
			ps->sorted++;
		}
		else
			ps->make_move(ps, "rb");
	}
	while (ontop--)
	{
		ps->make_move(ps, "ra");
		ps->sorted++;
	}
}

void	throw_right(t_push_swap *ps, size_t	q)
{
	while (q--)
	{
		if (((t_ps *)ps->a->top->content)->index == ps->sorted + 1)
		{
			ps->make_move(ps, "ra");
			ps->sorted++;
		}
		else
			ps->make_move(ps, "pb");
	}
}

void	push_swap(t_push_swap *ps)
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

void	solve_push_swap(t_push_swap *ps)
{
	size_t	thrown;

	thrown = throw_right_median(ps, (ps->a->maximum + ps->a->minimum + 1) / 2);
	push_swap(ps);
	throw_right(ps, ps->a->size - thrown);
	push_swap(ps);
	//push_swap(ps);
}
