/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:45:54 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/11 18:52:59 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include <limits.h>

void	f(t_list *elem)
{
	ft_putnbr(elem->content_size);
	ft_putchar(' ');
}

char	*ps_atoi(char *str, long long *num)
{
	int					sign;
	unsigned long long	result;

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

int		main(int ac, char **av)
{
	t_list	*head;

	if (ac == 1)
		return (0);
	if (!(head = create_list(av + 1, ac - 1)))
		ft_putendl_fd("Error", STDERR_FILENO);
	else
		ft_lstiter(head, f);
	return (0);
}
