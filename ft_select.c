/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:49:17 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/05/13 14:57:32 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_data	*stock_data(t_data *data, int mode)
{
	static t_data *tmp;
	if(mode == 1)
		tmp = data;
	return (tmp);
}

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
	t_data	*data;
	int ttyfd;

	i = 0;
	signal(SIGINT, signal_handler);
	signal(SIGWINCH, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
	data = NULL;
	if (isatty(1) == 0)
		ttyfd = open("/dev/tty", O_RDWR);
	else
		ttyfd = 1;
	if(tgetent(NULL, getenv("TERM")) == -1)
		return (-1);
	data = init(argc, argv, data);
	while(1)
	{
	stock_data(data, 1);
	if(data->dlist->head == NULL)
		quit(data->old_term);
	if(show_menu(data) == -1)
		quit(data->old_term);
	if (move(get_key(), data) == 2)
	{
		quit(data->old_term);
	}
	}
	return(quit(data->old_term));
}
