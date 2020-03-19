/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstsorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:27:28 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/15 17:29:02 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ps_lstsorted(t_list *lst, int (*cmp)(size_t a, size_t b))
{
	if (lst)
	{
		while (lst->next)
		{
			if (cmp(((t_ps *)(lst->content))->index, ((t_ps *)(lst->next->content))->index))
				return (0);
			lst = lst->next;
		}
	}
	return (1);
}
