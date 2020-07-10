/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sps_throw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 13:35:56 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/10 19:29:12 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

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

void	throw_right(t_push_swap *ps, size_t q)
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
