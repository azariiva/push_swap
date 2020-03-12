/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:57:37 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/12 20:26:14 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*next;
	t_list	*head;
	t_list	*ptr;

	if (!lst)
		return (NULL);
	next = lst->next;
	if (!(head = f(lst)))
		return (NULL);
	lst = next;
	ptr = head;
	while (lst && ptr)
	{
		next = lst->next;
		ptr->next = f(lst);
		ptr = ptr->next;
		lst = next;
	}
	return (head);
}
