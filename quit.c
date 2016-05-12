/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 12:10:54 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/05/12 15:58:24 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

struct termios get_oldterm()
{
	struct termios old_term;
	
	tcgetattr(0, &old_term);
	old_term.c_lflag |= (ICANON);
	old_term.c_lflag |= (ECHO);
	return (old_term);
}

int	restore_term(t_term old_term)
{
	int  i;

	tputs(tgetstr("ve", NULL), 0, ft_putchar2);
	i = tcsetattr(0, TCSADRAIN, &old_term);
	return (i);
}

int	quit(t_term old_term)
{
	restore_term(old_term);
	exit(0);
	return (0);
}
