/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:44:57 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/15 21:31:44 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libps.h"
#include <limits.h>
#include <stdio.h>

static int	cmp1(size_t a, size_t b)
{
	return (a > b);
}

static int	cmp2(size_t a, size_t b)
{
	return (a < b);
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

size_t		acts_movtop(t_list *lst, size_t size, size_t median)
{
	size_t	limit;
	size_t	i;

	limit = size / 2 + size % 2;
	i = -1;
	while (++i < limit)
	{
		if (((t_ps *)(lst->content))->index > median)
			return (i);
		lst = lst->next;
	}
	return (-1);
}

size_t		acts_movbot(t_list *lst, size_t size, size_t median)
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
		if (((t_ps *)(lst->content))->index > median)
			rv = size - i;
		lst = lst->next;
		i++;
	}
	return (rv);
}

void		ps_mov(t_psab *stacks)
{
	size_t	top_acts;
	size_t	bot_acts;
	size_t	i;
	size_t	size;
	size_t	median;
	size_t	j;

	size = stacks->size_a;
	median = (size - 1) / 2;
	j = -1;
	while (++j < size / 2)
	{
		top_acts = acts_movtop(stacks->a, stacks->size_a, median);
		bot_acts = acts_movbot(stacks->a, stacks->size_a, median);
		if (top_acts <= bot_acts)
		{
			i = -1;
			while (++i < top_acts)
				ps_ra(stacks);
		}
		else
		{
			i = -1;
			while (++i < bot_acts)
				ps_rra(stacks);
		}
		ps_pb(stacks);
	}
}

size_t		psfs_topacts(t_list *lst, size_t size, size_t index)
{
	size_t	limit;
	size_t	i;

	limit = size / 2 + size % 2;
	i = -1;
	while (++i < limit)
	{
		if (((t_ps *)(lst->content))->index == index)
			return (i);
		lst = lst->next;
	}
	return (-1);
}

size_t		psfs_botacts(t_list *lst, size_t size, size_t index)
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
		if (((t_ps *)(lst->content))->index == index)
			rv = size - i;
		lst = lst->next;
		i++;
	}
	return (rv);
}

void		psfs_mov(t_psab *stacks)
{
	size_t	acts_1st;
	size_t	acts_2nd;
	size_t	i;
	int		side_1st;
	int		side_2nd;

	while (stacks->size_b)
	{
		side_1st = 1;
		if ((int)(acts_1st = psfs_topacts(stacks->b, stacks->size_b, stacks->size_a)) == -1)
		{
			acts_1st = psfs_botacts(stacks->b, stacks->size_b, stacks->size_a);
			side_1st = -1;
		}
		side_2nd = 1;
		if ((int)(acts_2nd = psfs_topacts(stacks->b, stacks->size_b, stacks->size_a + 1)) == -1)
		{
			acts_2nd = psfs_botacts(stacks->b, stacks->size_b, stacks->size_a + 1);
			side_2nd = -1;
		}
		if (side_1st == side_2nd && acts_1st > acts_2nd)
		{
			i = -1;
			if (side_2nd == 1)
			{
				while (++i < acts_2nd)
					ps_rb(stacks);
				ps_pa(stacks);
				while (++i < acts_1st)
					ps_rb(stacks);

			}
			else
			{
				while (++i < acts_2nd)
					ps_rrb(stacks);
				ps_pa(stacks);
				while (i++ < acts_1st)
					ps_rrb(stacks);
			}
			ps_pa(stacks);
			ps_sa(stacks);
		}
		else
		{
			i = -1;
			if (side_1st == 1)
			{
				while (++i < acts_1st)
					ps_rb(stacks);
			}
			else
			{
				while (++i < acts_1st)
				{
					ps_rrb(stacks);
				}
			}
			ps_pa(stacks);
		}
	}
}

int	main(int ac, char **av)
{
	t_psab	stacks;

	if (ac == 1)
		return (0);
	if (!(stacks.a = ps_crtlst(av + 1, ac - 1)))
		throw_error();
	stacks.b = NULL;
	stacks.debug = 0;
	stacks.color = 1;
	stacks.size_a = ps_giveindex(stacks.a) + 1;
	stacks.size_b = 0;
	stacks.size = stacks.size_a;
	//ft_lstiter(stacks.a, ps_print_ext);
	while (stacks.size_a > 3)
	{
		ps_mov(&stacks);
		// ft_putendl("Step");
		// ft_lstiter(stacks.a, ps_print_ext);
	}
	if (stacks.size_a == 2)
	{
		if (ps_lstsorted(stacks.a, cmp2))
		{
			if (((t_ps *)(stacks.b->content))->index == 3)
				ps_sb(&stacks);
		}
		else
			((t_ps *)(stacks.b->content))->index == 2 ? ps_sa(&stacks) : ps_ss(&stacks);
		ps_pa(&stacks);
		ps_pa(&stacks);
	}
	else
	{
		if (((t_ps *)(stacks.a->content))->index == 2)
		{
			if (((t_ps *)(stacks.a->next->content))->index == 1)
			{
				// 2 1 0
			}
			else
			{
				// 2 0 1
			}
		}
		else if (((t_ps *)(stacks.a->content))->index == 1)
		{
			if (((t_ps *)(stacks.a->next->content))->index == 0)
			{
				// 1 0 2
			}
			else
			{
				// 1 2 0
			}
		}
		else
		{
			if (((t_ps *)(stacks.a->next->content))->index == 2)
			{
				// 0 2 1
			}
			else
			{
				// 0 1 2
			}
		}
	}
	psfs_mov(&stacks);
	return (0);
}
