/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_destructor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 14:03:27 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/15 10:28:03 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps_stack.h"

static void	del(void *content, size_t size)
{
	if (size && content)
		free(content);
}

void		stk_destructor(t_stack **self)
{
	if ((*self)->size)
		ft_lstdel(&((*self)->top), del);
	free(*self);
	*self = NULL;
}
