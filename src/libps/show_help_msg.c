/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_help_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:39:41 by blinnea           #+#    #+#             */
/*   Updated: 2020/07/14 12:44:21 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void			show_help_msg(void)
{
	ft_printf("Usage: checker [OPTION]... [NUMBERS]...\n\
	-v\t show stacks after each action\n\
	-c\t colorize stacks\n\
	-q\t show every action\n\
	-h\t display this help and exit\n\
	-s\t clear console after each action\n");
}
