/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 19:32:38 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/15 17:01:23 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_rrr(t_psab *stacks)
{
	ps_dact(&(stacks->a), &(stacks->b), ft_lstshftdown);
	ps_showact("rrr", stacks);
}
