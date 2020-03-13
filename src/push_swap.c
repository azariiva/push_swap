/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:44:57 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 23:52:02 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libps.h"
#include <limits.h>

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

size_t		acts_movtop(t_list *lst, size_t size, size_t median, int (*cmp)(size_t, size_t))
{
	size_t	limit;
	size_t	i;

	limit = size / 2 + size % 2;
	i = -1;
	while (++i < limit)
	{
		if (cmp(((t_ps *)(lst->content))->index, median))
			return (i);
		lst = lst->next;
	}
	return (-1);
}

size_t		acts_movbot(t_list *lst, size_t size, size_t median, int (*cmp)(size_t, size_t))
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
		if (cmp(((t_ps *)(lst->content))->index, median))
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
		top_acts = acts_movtop(stacks->a, stacks->size_a, median, cmp1);
		bot_acts = acts_movbot(stacks->a, stacks->size_a, median, cmp1);
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

int	main(int ac, char **av)
{
	t_psab	stacks;

	if (ac == 1)
		return (0);
	if (!(stacks.a = ps_crtlst(av + 1, ac - 1)))
		throw_error();
	stacks.b = NULL;
	stacks.debug = 1;
	stacks.size_a = ps_giveindex(stacks.a) + 1;
	stacks.size_b = 0;
	stacks.size = stacks.size_a;
	ft_lstiter(stacks.a, ps_print_ext);
	while (stacks.size_a > 3)
	{
		ps_mov(&stacks);
		// ft_putendl("Step");
		// ft_lstiter(stacks.a, ps_print_ext);
	}
	if (stacks.size_a == 2)
	{
		if (ps_lstsorted(stacks.a, cmp1) && ((t_ps *)(stacks.b->content))->index != 2)
				ps_sb(&stacks);
		else if (((t_ps *)(stacks.b->content))->index == 2)
				ps_sa(&stacks);
		else
			ps_ss(&stacks);
		ps_pa(&stacks);
		ps_pa(&stacks);
	}
	return (0);
}
