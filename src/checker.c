/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:45:54 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/12 01:19:20 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <limits.h>

void	f_print(t_list *elem)
{
	if (elem)
	{
		ft_putnbr(elem->content_size);
		if (elem->next)
			ft_putchar(' ');
	}
	else
		ft_putstr("NULL");
}

char	*ps_atoi(char *str, long long *num)
{
	int					sign;

	sign = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '-')
	{
		sign = 1;
		++str;
	}
	else if (*str == '+' && !ft_isdigit(*++str))
		return (NULL);
	*num = 0;
	while (ft_isdigit(*str))
	{
		*num = *num * 10 + (int)*str++ - '0';
		if ((!sign && *num > INT_MAX) || (sign && *num - 1 > INT_MAX))
			return (NULL);
	}
	if (sign)
		*num = -*num;
	return (str);
}

t_list	*create_list(char **src, int size)
{
	t_list		*head;
	t_list		*ptr;
	int			i;
	long long	num;
	char		*str;

	i = -1;
	head = NULL;
	while (++i < size)
	{
		str = src[i];
		while (*str)
		{
			if (!(str = ps_atoi(str, &num)) || (*str && !ft_isspace(*str)))
			{
				ft_lstdel_ic(&head);
				return (NULL);
			}
			if (head)
			{
				ptr->next = ft_lstnew(NULL, 0);
				ptr = ptr->next;
				ptr->content_size = (size_t)num;
			}
			else
			{
				head = ft_lstnew(NULL, 0);
				head->content_size = (size_t)num;
				ptr = head;
			}
		}
	}
	return (head);
}

int		ps_procui(t_list **a, t_list **b)
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

int		main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		puirv;
	
	if (ac == 1)
		return (0);
	if (!(a = create_list(av + 1, ac - 1)))
		ft_putendl_fd("Error", STDERR_FILENO);
	else
	{
		b = NULL;
		if ((puirv = ps_procui(&a, &b)) == -1)
			ft_putendl_fd("Error", STDERR_FILENO);
		else if (puirv == -2)
			ft_putendl_fd("Unexpected Error", STDERR_FILENO);
		else
			ft_lstiter(a, f_print);
		ft_lstdel_ic(&a);
		ft_lstdel_ic(&b);
	}
	return (0);
}
