#include "../includes/checker.h"

t_list	*ft_lstnew(void	*content, int content_size)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->content = ft_strdup(content);
	new->content_size = content_size;
	return (new);
}

void	ft_lst_pushback(t_list **lst, t_list *new)
{
	t_list *tmp;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_list	*ft_construct_list(int ac, char **av)
{
	t_list	*lst;
	int	i;

	i = 1;
	lst = NULL;
	while (i < ac)
	{
		ft_lst_pushback(&lst, ft_lstnew(av[i], sizeof(av[i])));
		i++;
	}
	return (lst);
}
