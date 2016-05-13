/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 13:17:47 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/05/13 14:04:57 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	sigint_handler(t_data *data)
{
	quit(data->old_term);
}

void	sigwinch_handler(t_data *data)
{
	ioctl(0, TIOCGWINSZ, &(data->win));
	data = stock_data(data, 1);
	tputs(tgetstr("cd", NULL), tgetnum("co"), ft_putchar2);
	show_menu(data);
}

void	sigtstp_handler(t_data *data)
{
	char cp[2];

	cp[0] = data->term.c_cc[VSUSP];
	cp[1] = 0;
	restore_term(data->old_term);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

void	sigcont_handler(t_data *data)
{
	tcsetattr(0, TCSADRAIN, &(data->term));
	show_menu(data);
	signal(SIGTSTP, signal_handler);
}

void	signal_handler(int signum)
{
	t_data *data;

	data = NULL;
	data = stock_data(data, 0);
	if(signum == SIGINT)
		sigint_handler(data);
	if(signum == SIGTSTP)
		sigtstp_handler(data);
	if(signum == SIGWINCH)
		sigwinch_handler(data);
	if(signum == SIGCONT)
		sigcont_handler(data);
}
