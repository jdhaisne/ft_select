/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:49:17 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/05/11 14:04:56 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*t_data	*stock_data(t_data *data, int mode)
{
	static t_data *tmp;
	if(mode == 1)
		data = tmp;
	return;
}*/

int ft_putchar2(int i)
{
	ft_putchar_fd(i, 2);
	return (i);
}

char *get_key()
{
	char *line;
	line = ft_strnew(3);
	read(0, line, 3);
	return(line);
}

int		main(int argc, char **argv)
{
	int i;
	t_term old_term;
	t_data	*data;
	int ttyfd;

	i = 0;
	signal(SIGINT, sighandler);
	data = NULL;
	if (isatty(1) == 0)
		ttyfd = open("/dev/tty", O_RDWR);
	else
		ttyfd = 1;
	if(tgetent(NULL, getenv("TERM")) == -1)
		return (-1);
		ft_putendl("A");
	data = init(argc, argv, data);
		ft_putendl("A");
	while(1)
	{
	if(show_menu(data) == -1)
		quit();
	if(data->dlist->head == NULL)
		quit();
	if (move(get_key(), data->dlist, data->old_term) == 2)
	{
		quit();
	}
	}
	return(quit(old_term));
}
