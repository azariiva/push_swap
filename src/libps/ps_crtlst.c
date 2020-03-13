/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_crtlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:58:06 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 17:22:20 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

static void	*f1(t_list **head)
{
	ft_lstdel(head, ps_del);
	return (NULL);
}

static void	f2(t_list **ptr, int val)
{
	(*ptr)->next = ps_lstnew(val);
	*ptr = (*ptr)->next;
}

static void	f3(t_list **head, t_list **ptr, int val)
{
	*head = ps_lstnew(val);
	*ptr = *head;
}

t_list	*ps_crtlst(char **src, int size)
{
	t_list		*head;
	t_list		*ptr;
	int			i;
	long long	num;
	char		*str;

	i = 0;
	head = NULL;
	while (i < size)
	{
		str = src[i++];
		while (*str)
		{
			while (ft_isspace(*str))
				++str;
			if (!*str)
				break;
			if (!(str = ps_atoi(str, &num)) || (*str && !ft_isspace(*str)) || \
			(head && ps_chcklst(head, num)))
				return (f1(&head));
			if (head)
				f2(&ptr, num);
			else
				f3(&head, &ptr, num);
		}
	}
	return (head);
}
