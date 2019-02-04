#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	void		*content;
	int		content_size;
	struct s_list	*next;
}		t_list;

void	ft_error(void);

void	ft_putstr(char *str);
int	ft_isdigit(char c);
int	ft_strcmp(char *s1, char *s2);
int	get_next_line_2(int fd, char **line);
void	ft_strdel(char **str);
char	*ft_strdup(char *str);
char	*ft_strnew(int size);
int	ft_is_sort(t_list *a, t_list *b);

t_list	*ft_lstnew(void *content, int content_size);
void	ft_lst_pushback(t_list **lst, t_list *next);
t_list	*ft_construct_list(int ac, char **av);

t_list	*ft_get_cmd(void);
void	ft_s(t_list *pile);
void	ft_ss(t_list *pile_a, t_list *pile_b);
void	ft_p(t_list *pile_a, t_list *pile_b);
void	ft_r(t_list *pile);
void	ft_rr(t_list *pile_a, t_list *pile_b);
void	ft_rrx(t_list *pile);
void	ft_rrr(t_list *pile_a, t_list *pile_b);

void	ft_apply(int ac, char **av);
void	ft_apply_cmd(char *cmd, t_list *pile_a, t_list *pile_b);

int	ft_check_par(int ac, char **av);
int	ft_check_cmd(t_list *cmd);

#endif
