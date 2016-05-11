/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:49:17 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/05/09 13:55:09 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char **argv)
{
	int i;
	int column_nb;
	int column;
	struct termios term;
	struct termios old_term;
	t_dlist	*dlist;
	int ttyfd;

	i = 0;
	signal(SIGINT, sighandler);
	if (isatty(1) == 0)
		ttyfd = open("/dev/tty", O_RDWR);
	else
		ttyfd = 1;
	if(tgetent(NULL, getenv("TERM")) == -1)
		return (-1);
	old_term = init(argc, argv, &dlist, ttyfd);
	while(1)
	{
	if(show_menu(dlist, 0, ttyfd) == -1)
		quit(old_term);
	if (move(get_key(), dlist, old_term, ttyfd) == 2)
		quit(old_term);
	}
	return(quit(old_term));
}
