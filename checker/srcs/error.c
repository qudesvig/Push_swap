#include "../includes/checker.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_SUCCESS);
}
