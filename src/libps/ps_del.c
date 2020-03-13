/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 14:40:53 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/13 14:41:43 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libps.h"

void	ps_del(void *content, size_t size)
{
	if (size && content)
		free(content);
}