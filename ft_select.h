/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:55:12 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/05/09 13:55:07 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>
# include <unistd.h>
# include <termcap.h>
# include <termios.h>
# include <signal.h>

typedef struct		s_dnode
{
	char			*data;
	int				cursor_on;
	int				selected;
	struct s_dnode	*next;
	struct s_dnode	*prev;
}					t_dnode;

typedef struct	s_dlist
{
	size_t	size;
	t_dnode	*head;
	t_dnode	*tail;
}				t_dlist;

t_dlist	*dlist_new();
t_dnode	*dnode_new(char *data);
t_dlist	*dlist_addtail(t_dlist *dlist, char *data);
t_dlist	*dlist_addhead(t_dlist *dlist, char *data);
struct termios	init(int argc, char **argv, t_dlist **dlist, int ttyfd);
char *get_key();
char	**split_tab(char **tab, int i);
int		get_max_word(t_dlist *dlist);
int ft_putchar2(int i);
int	quit(struct termios old_term);
int	move(char *key, t_dlist *dlist, struct termios old_term, int ttyfd);
void	print_word(t_dnode *tmp, int ttyfd);
t_dlist	*dlist_deln(t_dlist *dlist, int n);
int	show_menu(t_dlist *dlist, int nb_col, int ttyfd);
void	put_dlist(t_dlist *dlist, struct termios old_term, int ttyfd);
void	get_home_pos(int nb_line);
void	sighandler(int signum);

#endif
