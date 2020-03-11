#include "./libft/includes/libft.h"
#include <limits.h>

void	del(void *content, size_t content_size)
{
	content = content;
	content_size = content_size;
}

void	iterf(t_list *elem)
{
	ft_putendl(elem->content);
	ft_putnbr((int)(elem->content_size));
	ft_putendl("\n\n");
}

int		isdup(t_list *head, t_list *tail)
{
	t_list	*ptr;

	ptr = head;
	while (ptr != tail)
	{
		if (ptr->content_size == tail->content_size)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int		check_and_atoi(t_list *head)
{
	t_list				*ptr;
	unsigned long long	num;
	char const			*str;
	int					sign;

	ptr = head;
	while (ptr)
	{
		str = ptr->content;
		sign = 0;
		num = 0;
		if (*str == '-')
		{
			sign = 1;
			++str;
		}
		else if (*str == '+')
			++str;
		while (*str)
		{
			if (*str && !isdigit(*str))
				return (-1);
			num = num * 10 + (int)*str++ - '0';
			if ((!sign && num > INT_MAX) || (sign && num - 1 > INT_MAX))
				return (-1);
		}
		ptr->content_size = (sign ? -num : num);
		if (isdup(head, ptr))
			return (-1);
		ptr = ptr->next;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_list	*head;
	char	**warr;
	int		i;

	av[ac] = NULL;
	warr = av;
	if (ac <= 1)
		return (0);
	else if (ac == 2)
		warr = ft_strsplit(av[1], ' ');
	head = NULL;
	i = -1;
	while (warr[++i])
		ft_lstadd(&head, ft_lstnew(warr[i], ft_strlen(warr[i])));
	
	if (check_and_atoi(head) == -1)
	{
		ft_lstdel(&head, del);
		ft_putendl_fd("Error", STDERR_FILENO);
		return (0);
	}
	ft_lstiter(head, iterf);
	ft_lstdel(&head, del);
	return (0);
}