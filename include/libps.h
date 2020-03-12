/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:55:31 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/12 21:34:02 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H

# define LIBPS_H

# include "libft.h"
# include "get_next_line.h"
# include <limits.h>

int		ps_chcklst(t_list *lst, int content_size);
char	*ps_atoi(char *str, long long *num);
t_list	*ps_crtlst(char **src, int size);
int		ps_procui(t_list **a, t_list **b);

#endif
