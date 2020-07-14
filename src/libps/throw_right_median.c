/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_right_median.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:58:52 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/14 16:59:01 by blinnea          ###   ########.fr       */
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
