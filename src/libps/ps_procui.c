/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_procui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 21:06:26 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 18:38:48 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int			ps_procui(t_list **a, t_list **b, int debug)
{
	char	*line;
	ssize_t	gnlrv;

	while ((gnlrv = get_next_line(STDIN_FILENO, &line)))
	{
		if (gnlrv < 0)
			return (-2);
		if (!ft_strcmp(line, "sa"))
			ft_lstswptop(a);
		else if (!ft_strcmp(line, "sb"))
			ft_lstswptop(b);
		else if (!ft_strcmp(line, "ss"))
			ps_dact(a, b, ft_lstswptop);
		else if (!ft_strcmp(line, "pa"))
			ft_lsttrans(a, b);
		else if (!ft_strcmp(line, "pb"))
			ft_lsttrans(b, a);
		else if (!ft_strcmp(line, "ra"))
			ft_lstshftup(a);
		else if (!ft_strcmp(line, "rb"))
			ft_lstshftup(b);
		else if (!ft_strcmp(line, "rr"))
			ps_dact(a, b, ft_lstshftup);
		else if (!ft_strcmp(line, "rra"))
			ft_lstshftdown(a);
		else if (!ft_strcmp(line, "rrb"))
			ft_lstshftdown(b);
		else if (!ft_strcmp(line, "rrr"))
			ps_dact(a, b, ft_lstshftdown);
		else
		{
			// TODO: try to clear fdlist from get_next_line
			/*
			ft_putstr_fd("Error in line: ",STDERR_FILENO);
			ft_putendl(line);
			*/
			ft_strdel(&line);
			return (-1);
		}
		ft_strdel(&line);
		if (debug)
			ps_debuginfo(*a, *b);
	}
	return (0);
}
