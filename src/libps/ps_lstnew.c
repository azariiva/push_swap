/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 14:35:28 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 16:37:03 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

t_list	*ps_lstnew(int val)
{
	t_ps	new;

	new.val = val;
	new.index = 0;
	return (ft_lstnew(&new, sizeof(new)));
}