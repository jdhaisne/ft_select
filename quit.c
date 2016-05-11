/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 12:10:54 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/05/11 12:27:02 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

struct termios get_oldterm()
{
	struct termios old_term;
	
	tcgetattr(0, &old_term);
	old_term.c_lflag = (ICANON);
	old_term.c_lflag = (ECHO);
	return (old_term);
}

int	quit()
{
	struct termios old_term;

	old_term = get_oldterm();
	tputs(tgetstr("ve", NULL), 0, ft_putchar2);
	tcsetattr(0, TCSADRAIN, &old_term);
	exit(0);
	return (0);
}
