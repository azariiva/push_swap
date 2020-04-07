/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:44:57 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/23 16:47:24 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libps.h"
#include <limits.h>
#include <stdio.h>

static const int	cmpA(size_t current, size_t next)
{
	return (current < next);
}

static const int	cmpB(size_t current, size_t next)
{
	return (next < current);
}

static void	ps_print_ext(t_list *elem)
{
	ft_putnbr(((t_ps *)(elem->content))->val);
	ft_putstr("\t\t");
	ft_putnbr(((t_ps *)(elem->content))->index);
	ft_putchar('\n');
}

static void	throw_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(0);
}

size_t		find_tacts(t_list *lst, size_t size, size_t median, const int (*cmp)(size_t, size_t))
{
	size_t	limit;
	size_t	i;

	limit = size / 2 + size % 2;
	i = -1;
	while (++i < limit)
	{
		if (cmp(((t_ps *)lst->content)->index, median))
			return (i);
		lst = lst->next;
	}
	return (-1);
}

size_t		find_bacts(t_list *lst, size_t size, size_t median, const int (*cmp)(size_t, size_t))
{
	size_t	skip;
	size_t	i;
	size_t	rv;

	skip = size / 2 + size % 2;
	i = 0;
	while (i < skip)
	{
		lst = lst->next;
		i++;
	}
	rv = -1;
	while (i < size)
	{
		if (cmp(((t_ps *)lst->content)->index, median))
			rv = size - i;
		lst = lst->next;
		i++;
	}
	return (rv);
}

size_t		find_median(t_list *lst, size_t size)
{
	size_t	minelem;
	size_t	maxelem;
	size_t	i;

	minelem = (size_t)-1;
	maxelem = 0;
	i = -1;
	while (lst && ++i < size)
	{
		if (((t_ps *)lst->content)->index < minelem)
			minelem = ((t_ps *)lst->content)->index;
		if (((t_ps *)lst->content)->index > maxelem)
			maxelem = ((t_ps *)lst->content)->index;
		lst = lst->next;
	}
	return (minelem + maxelem + 1) / 2;
}

void		ps_movB(t_psab *stacks)
{
	size_t	tacts;
	size_t	bacts;
	size_t	median;
	size_t	i;

	median = find_median(stacks->a, stacks->size_a);
	while (1)
	{
		tacts = find_tacts(stacks->a, stacks->size_a, median, cmpA);
		bacts = find_bacts(stacks->a, stacks->size_a, median, cmpA);
		if (tacts == (size_t)-1 && bacts == (size_t)-1)
			break;
		i = -1;
		if (tacts > bacts)
		{
			while (++i < bacts)
				ps_rra(stacks);
			ps_pb(stacks);
		}
		else
		{
			while (++i < tacts)
				ps_ra(stacks);
			ps_pb(stacks);
		}
	}
}

void		ps_movAtop(t_psab *stacks, size_t median, size_t acts)
{
	size_t	i;

	while (1)
	{
		if (acts == -1)
			return ;
		i = -1;
		while (++i < acts)
		{
			if (((t_ps *)stacks->b->content)->index == stacks->lsindex)
			{
				ps_pa(stacks);
				stacks->lsindex++;
				++i;
				while (((t_ps *)stacks->b->content)->index == stacks->lsindex)
				{
					ps_ra(stacks);
					ps_pa(stacks);
					++i;
					stacks->lsindex++;
				}
				if (i < acts)
					ps_rr(stacks);
				else
					ps_ra(stacks);
			}
			else
				ps_rb(stacks);
		}
		if (i == acts)
			ps_pa(stacks);
		acts = find_tacts(stacks->b, stacks->size_b, median, cmpB);
	}
}

void		ps_movAbot(t_psab *stacks, size_t median, size_t acts)
{
	size_t	i;

	while (1)
	{
		if (acts == -1)
			return ;
		i = -1;
		while (++i < acts)
		{
			while (((t_ps *)stacks->b->content)->index == stacks->lsindex)
			{
				ps_pa(stacks);
				ps_ra(stacks);
				stacks->lsindex++;
			}
			ps_rrb(stacks);
		}
		ps_pa(stacks);
		acts = find_bacts(stacks->b, stacks->size_b, median, cmpB);
	}
}


void		ps_movA(t_psab *stacks)
{
	size_t	tacts;
	size_t	bacts;
	size_t	median;

	median = find_median(stacks->b, stacks->size_b);
	tacts = find_tacts(stacks->b, stacks->size_b, median, cmpB);
	bacts = find_bacts(stacks->b, stacks->size_b, median, cmpB);
	(tacts <= bacts ? ps_movAtop(stacks, median, tacts) : ps_movAbot(stacks, median, bacts));
	if (stacks->size_b >= 13)
		ps_movA(stacks);
}

int	main(int ac, char **av)
{
	t_psab	stacks;

	if (ac == 1)
		return (0);
	if (!(stacks.a = ps_crtlst(av + 1, ac - 1)))
		throw_error();
	stacks.b = NULL;
	stacks.debug = 1;
	stacks.color = 1;
	stacks.lsindex = 1;
	stacks.size_a = ps_giveindex(stacks.a);
	stacks.size_b = 0;
	stacks.size = stacks.size_a;
	ps_movB(&stacks);
	ps_movA(&stacks);
	return (0);
}
