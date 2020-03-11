/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshftup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:44:45 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/11 22:57:50 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstshftup(t_list **lst)
{
    t_list  *head;
    t_list  *iter;
    
    head = ft_lstpoptop(lst);
    iter = *lst;
    while (iter->next)
        iter = iter->next;
    iter->next = head;
}