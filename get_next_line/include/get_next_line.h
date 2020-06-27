/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:28:36 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/14 12:40:28 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 3

enum
{
	ERR = -1,
	OK = 1,
	END = 0
};

int	get_next_line(const int fd, char **line);

#endif
