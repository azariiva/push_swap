/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_ic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:19:01 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/11 18:19:41 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstdel_ic(t_list **alst)
{
    t_list	*ptr;
	t_list	*todel;

	ptr = *alst;
	while (ptr)
	{
		todel = ptr;
		ptr = ptr->next;
		ft_lstdelone_ic(&todel);
	}
	*alst = NULL;
}