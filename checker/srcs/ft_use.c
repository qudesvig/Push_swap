#include "../includes/checker.h"

int	ft_isdigit(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int	i;

	i = 0;
	if (!(ret = ft_strnew(ft_strlen(str))))
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_strdel(char **str)
{
	free(str);
	*str = NULL;
}

char	*ft_strnew(int size)
{
	char	*str;
	int	i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

int	get_next_line_2(int fd, char **line)
{
	int	i;
	char	c;

	i = 0;
	*line = ft_strnew(4);
	c = 0;
	while (read(fd, &c, 1) && c != '\n')
	{
		*(line[i]) = c;
		i++;
	}
	return (1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int	ft_is_sort(t_list *a, t_list *b)
{
	t_list *ta;
	t_list *tb;

	if (b || !a)
		return (0);
	ta = a;
	tb = ta->next;
	while (tb)
	{
		if (ft_strcmp(ta->content, tb->content) >= 0)
			return (0);
		tb = tb->next;
		ta = ta->next;
	}
	return (1);
}
