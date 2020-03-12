/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chcklst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:52:56 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/12 20:31:39 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int	ps_chcklst(t_list *lst, int content_size)
{
	while (lst)
	{
		if ((int)lst->content_size == content_size)
			return (1);
		lst = lst->next;
	}
	return (0);
}
