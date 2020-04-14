/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 11:11:14 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/14 13:27:55 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"


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
			return (-4); // error during reading
		}
		if (ps->make_move(ps, line))
		{
			ft_strdel(&line);
			get_next_line(-1, &line);
			return (-1); // wrong input
		}
		ft_strdel(&line);
	}
	get_next_line(-1, &line);
	return (0); // everything is fine
}

int			main(int ac, char **av)
{
	t_push_swap	*ps;
	char		**ptr;
	char		*str;
	char		vcq[3];

	ft_bzero(vcq, sizeof(vcq));
	if (ac == 1)
		return (0);
	ptr = av + 1;
	while (1)
	{
		str = *ptr;
		if (*str != '-' || ft_isdigit(str[1]))
			break;
		if (!str[1])
			throw_error();
		while (*++str)
		{
			if (*str == 'v')
				vcq[0] = 1;
			else if (*str == 'c')
				vcq[1] = 1;
			else if (*str == 'a')
				vcq[2] = 1;
			else
				throw_error();
		}
		ptr++;
	}
	if (!(ps = new_push_swap(ptr, ac - (ptr - av), vcq)))
		throw_error();
	if (ps->visualize)
		ps->show_stacks(ps);
	if (procui(ps))
	{
		ps->destructor(&ps);
		throw_error();
	}
	ft_putendl((ps->b->size == 0 && ps->a->sorted(ps->a) == ASCENDING) ? \
	"OK" : "KO");
	ps->destructor(&ps);
	return (0);
}
