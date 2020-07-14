/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 13:35:56 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/14 16:59:59 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

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
