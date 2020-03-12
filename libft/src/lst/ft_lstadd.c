/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:50:09 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/12 20:26:03 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	*alst = new;
	new->next = tmp;
}
