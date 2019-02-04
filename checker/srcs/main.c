#include "../includes/checker.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		ft_error();
	else
		ft_apply(ac, av);
	return (0);
}
