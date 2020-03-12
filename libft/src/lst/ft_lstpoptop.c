/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoptop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:10:34 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/12 20:26:28 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list	*ft_lstpoptop(t_list **lst)
{
	t_list	*head;

	if (!lst || !(head = *lst))
		return (NULL);
	*lst = head->next;
	head->next = NULL;
	return (head);
}
