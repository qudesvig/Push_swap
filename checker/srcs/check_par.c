#include "../includes/checker.h"

int	ft_check_cmd(t_list *cmd)
{
	t_list *tmp;

	tmp = cmd;
	while (tmp)
	{
		if (ft_strcmp(tmp->content, "sa") != 0
			&& ft_strcmp(tmp->content, "sb") != 0
			&& ft_strcmp(tmp->content, "ss") != 0
			&& ft_strcmp(tmp->content, "pa") != 0
			&& ft_strcmp(tmp->content, "pb") != 0
			&& ft_strcmp(tmp->content, "ra") != 0
			&& ft_strcmp(tmp->content, "rb") != 0
			&& ft_strcmp(tmp->content, "rr") != 0
			&& ft_strcmp(tmp->content, "rra") != 0
			&& ft_strcmp(tmp->content, "rrb") != 0
			&& ft_strcmp(tmp->content, "rrr") != 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_check_par(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
			ft_putstr("test");
		if (ft_strcmp(av[i], "2147483647") > 0)
			return (0);
			ft_putstr("test");
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
