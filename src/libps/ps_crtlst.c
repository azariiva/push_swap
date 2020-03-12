/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_crtlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:58:06 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/12 20:58:33 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

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
