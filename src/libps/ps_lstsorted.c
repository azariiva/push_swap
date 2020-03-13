/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstsorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:27:28 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 23:34:22 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ps_lstsorted(t_list *lst, int (*cmp)(size_t a, size_t b))
{
	while (lst)
	{
		if (lst->next && \
		cmp(((t_ps *)(lst->next->content))->index, ((t_ps *)(lst->content))->index))
			return (0);
		lst = lst->next;
	}
	return (1);
}
