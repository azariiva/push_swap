/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:55:31 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/15 16:53:56 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H

# define LIBPS_H

# include "libft.h"
# include "get_next_line.h"
# include <limits.h>

# define RESET_CONSOLE "\033[0m"
# define GREEN_FONT "\033[32m"
# define RED_FONT "\033[31m"
# define BLUE_FONT "\033[34m"

typedef struct	s_ps
{
	int		val;
	size_t	index;
}				t_ps;

typedef struct	s_psab
{
	t_list	*a;
	t_list	*b;
	size_t	size;
	size_t	size_a;
	size_t	size_b;
	int		debug;
	int		color;
}				t_psab;

void			ps_del(void *content, size_t size);
t_list			*ps_lstnew(int val);
int				ps_chcklst(t_list *lst, int content_size);
char			*ps_atoi(char *str, long long *num);
t_list			*ps_crtlst(char **src, int size);
int				ps_procui(t_list **a, t_list **b, int debug);
void			ps_print(t_list *elem);
void			ps_debuginfo(t_list *a, t_list *b);
int				ps_lstsorted(t_list *lst, int (*cmp)(size_t, size_t));
size_t			ps_giveindex(t_list *lst);
/*
** Do action act on lists A and B.
*/
void			ps_dact(t_list **a, t_list **b, void (*act)(t_list **));
/*
** Actions from task as they called in task.
*/
void			ps_sa(t_psab *stacks);
void			ps_sb(t_psab *stacks);
void			ps_ss(t_psab *stacks);
void			ps_pa(t_psab *stacks);
void			ps_pb(t_psab *stacks);
void			ps_ra(t_psab *stacks);
void			ps_rb(t_psab *stacks);
void			ps_rr(t_psab *stacks);
void			ps_rra(t_psab *stacks);
void			ps_rrb(t_psab *stacks);
void			ps_rrr(t_psab *stacks);
/*
** Shows stacks status.
*/
void			ps_showstcks(t_psab *stacks);
/*
** Shows action done on stack.
*/
void	ps_showact(char *action, t_psab *stacks);

#endif
