#include "../includes/checker.h"

void	ft_s(t_list *pile)
{
	t_list *tmp;

	if (!pile || !(pile->next))
		return ;
	tmp = pile->next;
	pile->next = tmp->next;
	tmp->next = pile;
	pile = tmp;
}

void	ft_ss(t_list *pile_a, t_list *pile_b)
{
	ft_s(pile_a);
	ft_s(pile_b);
}

void	ft_p(t_list *pile_a, t_list *pile_b)
{
	t_list *tmp;

	if (!pile_a)
		return ;
	tmp = pile_a;
	pile_a = pile_a->next;
	tmp->next = pile_b;
}

void	ft_rrx(t_list *pile)
{
	t_list *tmp;

	if (!pile || !(pile->next))
		return ;
	tmp = pile;
	while (tmp->next)
		tmp = tmp->next;
	pile->next = NULL;
	tmp->next = pile;
	pile = tmp;
}

void	ft_rr(t_list *pile_a, t_list *pile_b)
{
	ft_r(pile_a);
	ft_r(pile_b);
}

void	ft_r(t_list *pile)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!pile || !(pile->next))
		return ;
	tmp = pile;
	pile = pile->next;
	tmp2 = pile;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	
}

void	ft_rrr(t_list *pile_a, t_list *pile_b)
{
	ft_rrx(pile_a);
	ft_rrx(pile_b);
}

void	ft_apply_cmd(char *cmd, t_list *pile_a, t_list *pile_b)
{
	if (ft_strcmp(cmd, "sa") == 0)
		ft_s(pile_a);
	else if (ft_strcmp(cmd, "sb") == 0)
		ft_s(pile_b);
	else if (ft_strcmp(cmd, "ss") == 0)
		ft_ss(pile_a, pile_b);
	else if (ft_strcmp(cmd, "pa") == 0)
		ft_p(pile_a, pile_b);
	else if (ft_strcmp(cmd, "pb") == 0)
		ft_p(pile_b, pile_a);
	else if (ft_strcmp(cmd, "ra") == 0)
		ft_r(pile_a);
	else if (ft_strcmp(cmd, "rb") == 0)
		ft_r(pile_b);
	else if (ft_strcmp(cmd, "rr") == 0)
		ft_rr(pile_a, pile_b);
	else if (ft_strcmp(cmd, "rra") == 0)
		ft_rrx(pile_a);
	else if (ft_strcmp(cmd, "rrb") == 0)
		ft_rrx(pile_b);
	else if (ft_strcmp(cmd, "rrr") == 0)
		ft_rrr(pile_a, pile_b);
}

void	ft_apply(int ac, char **av)
{
	t_list	*cmd;
	t_list	*pile_a;
	t_list	*pile_b;

	pile_b = NULL;
	if (!ft_check_par(ac, av))
		ft_error();
	pile_a = ft_construct_list(ac, av);
	cmd = ft_get_cmd();
	if (!ft_check_cmd(cmd))
		ft_error();
	while (cmd)
	{
		ft_apply_cmd(cmd->content, pile_a, pile_b);
		cmd = cmd->next;
	}
	if (ft_is_sort(pile_a, pile_b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
