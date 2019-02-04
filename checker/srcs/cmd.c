#include "../includes/checker.h"

t_list	*ft_get_cmd(void)
{
	t_list	*cmd;
	char	*str;

	cmd = NULL;
	while (get_next_line_2(0, &str) > 0)
	{
		ft_lst_pushback(&cmd, ft_lstnew(str, sizeof(str)));
		ft_strdel(&str);
	}
	return (cmd);
}
