/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_left_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:55:08 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/14 16:57:38 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

static int		tvoi_rot(t_push_swap *ps, int *rot, const char *act)
{
	if (*rot)
	{
		ps->make_move(ps, act);
		ps->sorted++;
		*rot = 0;
		return (1);
	}
	return (0);
}

static void		naoborot(t_push_swap *ps, int *rot)
{
	if (((t_ps *)ps->b->top->content)->index == ps->b->minimum)
	{
		tvoi_rot(ps, rot, "ra");
		ps->make_move(ps, "pa");
		*rot = 1;
	}
	else if (!tvoi_rot(ps, rot, "rr"))
		ps->make_move(ps, "rb");
}

void			throw_left_sorted(t_push_swap *ps)
{
	size_t	ontop;
	int		rot;

	rot = 0;
	ontop = 0;
	while (ps->b->size)
	{
		if (((t_ps *)ps->b->top->content)->index == ps->b->maximum)
		{
			tvoi_rot(ps, &rot, "ra");
			ps->make_move(ps, "pa");
			ontop++;
		}
		else
			naoborot(ps, &rot);
	}
	tvoi_rot(ps, &rot, "ra");
	while (ontop--)
	{
		ps->make_move(ps, "ra");
		ps->sorted++;
	}
}
