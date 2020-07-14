/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 11:11:14 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/14 12:49:17 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <unistd.h>
#include <stdlib.h>

static void	throw_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(0);
}

static int	procui(t_push_swap *ps)
{
	char	*line;
	ssize_t	rv;

	while ((rv = get_next_line(STDIN_FILENO, &line)))
	{
		if (rv < 0)
		{
			get_next_line(-1, &line);
			return (READ_ERROR);
		}
		if (ps->make_move(ps, line))
		{
			ft_strdel(&line);
			get_next_line(-1, &line);
			return (WRONG_INPUT);
		}
		ft_strdel(&line);
	}
	get_next_line(-1, &line);
	return (OK);
}

int			parse_av(int ac, char **av, char vcqs[4])
{
	char opt;

	ft_bzero(vcqs, 4 * sizeof(char));
	while ((opt = ft_getopt(ac, av, FLAGS)) != -1)
	{
		if (opt == 'v')
			vcqs[0] = 1;
		else if (opt == 'c')
			vcqs[1] = 1;
		else if (opt == 'q')
			vcqs[2] = 1;
		else if (opt == 's')
			vcqs[3] = 1;
		else if (opt == 'h')
		{
			show_help_msg();
			return (-1);
		}
		else
		{
			show_illegal_opt(g_optopt);
			return (-1);
		}
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_push_swap	*ps;
	char		vcqs[4];

	if (ac == 1)
		return (0);
	if (parse_av(ac, av, vcqs) == -1)
		return (0);
	if (!(ps = new_push_swap(av + g_optind, ac - g_optind, vcqs)))
		throw_error();
	if (ps->visualize)
	{
		ps->show_stacks(ps);
		clear_if_step(ps);
	}
	if (procui(ps))
	{
		ps->destructor(&ps);
		throw_error();
	}
	ft_putendl((ps->b->size == 0 && ps->a->sorted(ps->a) & ASCENDING) ? \
	"OK" : "KO");
	ps->destructor(&ps);
	return (0);
}
