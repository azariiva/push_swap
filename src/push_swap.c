/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:44:57 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/12 19:55:14 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libps.h"
#include <limits.h>

t_list	*ps_crtlst(char **src, int size)
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
			if (!(str = ps_atoi(str, &num)) || (*str && !ft_isspace(*str)) || \
			(head && ps_chcklst(head, num)))
			{
				ft_lstdel_ic(&head);
				return (NULL);
			}
			if (head)
			{
				ptr->next = ft_lstnew_ic((size_t)num);
				ptr = ptr->next;
			}
			else
			{
				head = ft_lstnew_ic((size_t)num);
				ptr = head;
			}
		}
	}
	return (head);
}



int	main(int ac, char **av)
{
	t_list	*a;
	int		puirv;

	if (ac == 1)
		return (0);
	if (!(a = ps_crtlst(av + 1, ac - 1)))
		ft_putendl_fd("Error", STDERR_FILENO);
	else
	{

		ft_lstdel_ic(&a);
		ft_lstdel_ic(&b);
	}
	return (0);
}
