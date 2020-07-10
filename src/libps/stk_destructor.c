/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_destructor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 14:03:27 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/10 18:38:18 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps_stack.h"

static void	del(void *content, size_t size)
{
	if (size && content)
		ft_memdel((void **)&content);
}

void		stk_destructor(t_stack **self)
{
	if ((*self)->size)
		ft_lstdel(&((*self)->top), del);
	ft_memdel((void **)self);
	*self = NULL;
}
