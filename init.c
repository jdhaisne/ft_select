/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:49:58 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/05/11 13:37:15 by jdhaisne         ###   ########.fr       */
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

t_data *init_data(t_data *data, int argc, char **argv, t_term old_term)
{
	data = (t_data *)malloc(sizeof(t_data));
	data->dlist = create_list(argc, argv);
	data->old_term = old_term;
	ioctl(0, TIOCGWINSZ, &(data->win));
	if (isatty(1) == 0)
		data->ttyfd = open("/dev/tty", O_RDWR);
	else
		data->ttyfd = 1;
	return(data);
}

t_data *init(int argc, char **argv, t_data *data)
{
	t_term term;
	t_term old_term;

	tcgetattr(0, &term);
	tcgetattr(0, &old_term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &term);
	data = init_data(data, argc, argv, old_term);
	//tputs(tgetstr("vi", NULL), 0, ft_putchar2);
		return (data);
}
