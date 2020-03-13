/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_giveindex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:26:59 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 16:52:19 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

static size_t	psgi_helper(t_list *lst)
{
	t_list	*ptr;

	if (lst)
	{
		ptr = lst->next;
		while (ptr)
		{
			if (((t_ps *)(ptr->content))->val > ((t_ps *)(lst->content))->val)
				((t_ps *)(lst->content))->index++;
			else
				((t_ps *)(ptr->content))->index++;
			ptr = ptr->next;
		}
	}
	return (((t_ps *)(lst->content))->index);
}

size_t			ps_giveindex(t_list *lst)
{
	t_list	*ptr;
	size_t	maxindex;
	size_t	psgih_rv;

	maxindex = 0;
	if (lst)
	{
		ptr = lst->next;
		while (ptr)
		{
			if (((t_ps *)(ptr->content))->val > ((t_ps *)(lst->content))->val)
				((t_ps *)(lst->content))->index++;
			else
				((t_ps *)(ptr->content))->index++;
			if ((psgih_rv = psgi_helper(ptr)) > maxindex)
				maxindex = psgih_rv;
			ptr = ptr->next;
		}
	}
	return (maxindex > ((t_ps *)(lst->content))->index ? \
	maxindex : ((t_ps *)(lst->content))->index);
}
