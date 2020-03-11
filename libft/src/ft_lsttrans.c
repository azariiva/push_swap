/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttrans.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 22:23:07 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/11 22:50:14 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lsttrans(t_list **dst, t_list **src)
{
    t_list  *lst;

    if ((lst = ft_lstpoptop(src)))
        ft_lstadd(dst, lst);
}