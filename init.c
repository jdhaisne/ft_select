/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:49:58 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/05/08 16:19:39 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_dlist	*create_list(int argc, char **argv)
{
	t_dlist	*new;
	int		i;

	i = 1;
	new = dlist_new();
	
	if(new != NULL)
	{
	while(i < argc)
	{
		new = dlist_addtail(new, argv[i]);
		i++;
	}
	}
	return (new);
}

struct termios	init(int argc, char **argv, t_dlist **dlist, int ttyfd)
{
	struct termios term;
	struct termios old_term;

	tcgetattr(0, &term);
	tcgetattr(0, &old_term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &term);
	*dlist = create_list(argc, argv);
	//tputs(tgetstr("vi", NULL), 0, ft_putchar2);
		return (old_term);
}
