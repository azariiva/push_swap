/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswptop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:03:36 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/11 22:18:44 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstswptop(t_list **lst)
{
    t_list  *tmp;

    if (lst && *lst && (*lst)->next)
    {
        tmp = (*lst)->next;
        (*lst)->next = tmp->next;
        tmp->next = *lst;
        *lst = tmp;
    }
}
