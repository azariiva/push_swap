/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:09:17 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/12 20:07:36 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_io.h"

int		ft_putchar_fd(char c, int fd)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (write(fd, &uc, sizeof(uc)) == sizeof(uc))
		return (c);
	else
		return (EOF);
}
