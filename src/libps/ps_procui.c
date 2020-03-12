/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_procui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 21:06:26 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/12 21:24:25 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ps_procui(t_list **a, t_list **b)
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
		{
			ft_lstswptop(a);
			ft_lstswptop(b);
		}
		else if (!ft_strcmp(line, "pa"))
			ft_lsttrans(a, b);
		else if (!ft_strcmp(line, "pb"))
			ft_lsttrans(b, a);
		else if (!ft_strcmp(line, "ra"))
			ft_lstshftup(a);
		else if (!ft_strcmp(line, "rb"))
			ft_lstshftup(b);
		else if (!ft_strcmp(line, "rr"))
		{
			ft_lstshftup(a);
			ft_lstshftup(b);
		}
		else if (!ft_strcmp(line, "rra"))
			ft_lstshftdown(a);
		else if (!ft_strcmp(line, "rrb"))
			ft_lstshftdown(b);
		else if (!ft_strcmp(line, "rrr"))
		{
			ft_lstshftdown(a);
			ft_lstshftdown(b);
		}
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
		line = NULL;
	}
	return (0);
}
