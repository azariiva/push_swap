/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_fill_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 14:13:43 by blinnea           #+#    #+#             */
/*   Updated: 2020/04/14 14:50:10 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps_push_swap.h"

static int		giveindex(t_list *top, t_list *ptr)
{
	while (top != ptr)
	{
		if (((t_ps *)ptr->content)->val < ((t_ps *)top->content)->val)
			((t_ps *)top->content)->index++;
		else if (((t_ps *)ptr->content)->val == ((t_ps *)top->content)->val)
			return (WRONG_INPUT);
		else
			((t_ps *)ptr->content)->index++;
		top = top->next;
	}
	return (OK);
}

static t_list	*lstnew(int val)
{
	t_ps	new;

	new.val = val;
	new.index = 1;
	return (ft_lstnew(&new, sizeof(new)));
}

int				psw_fill_stack(t_stack *stk, char **src, int size)
{
	int			i;
	t_list		*ptr;
	long long	num;
	int			sign;
	char		*str;

	i = 0;
	while (i < size)
	{
		str = src[i++];
		while (*str)
		{
			while (ft_isspace(*str))
				++str;
			if (!*str)
				break ;
			sign = (*str == '-' ? 1 : 0);
			str += (*str == '+' || *str == '-');
			if (!ft_isdigit(*str))
				return (WRONG_INPUT);
			num = 0;
			while (ft_isdigit(*str))
			{
				num = num * 10 + *str++ - '0';
				if ((!sign && num > INT_MAX) || (sign && num - 1 > INT_MAX))
					return (WRONG_INPUT);
			}
			stk->size++;
			if (stk->top)
			{
				if (!(ptr->next = lstnew(sign ? -num : num)))
					return (ALLOCATION_ERROR);
				ptr = ptr->next;
				if (giveindex(stk->top, ptr))
					return (WRONG_INPUT);
			}
			else
			{
				if (!(stk->top = lstnew(sign ? -num : num)))
					return (ALLOCATION_ERROR);
				ptr = stk->top;
			}
		}
	}
	return (OK);
}
