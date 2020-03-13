/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_debuginfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:07:47 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 15:10:44 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ps_debuginfo(t_list *a, t_list *b)
{
	ft_putstr("List A: ");
	ft_lstiter(a, ps_print);
	ft_putstr("\nList B: ");
	ft_lstiter(b, ps_print);
	ft_putstr("\n\n");
}
