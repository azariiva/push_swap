/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chcklst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:52:56 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 14:52:49 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ps_chcklst(t_list *lst, int val)
{
	while (lst)
	{
		if (((t_ps *)(lst->content))->val == val)
			return (1);
		lst = lst->next;
	}
	return (0);
}
