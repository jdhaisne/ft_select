/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 12:42:06 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/05/09 13:02:33 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	go_left(t_dlist *dlist)
{
	t_dnode	*start;

	start = dlist->head;
	while(start != NULL && start->cursor_on == 0)
		start = start->next;
	if(start->prev != NULL)
		start->prev->cursor_on = 1;
	else if (start->next != NULL)
		dlist->tail->cursor_on = 1;
	else
		return;
	start->cursor_on = 0;

}

void	go_right(t_dlist *dlist)
{
	t_dnode	*start;

	start = dlist->head;
	while(start != NULL && start->cursor_on == 0)
		start = start->next;
	if(start->next != NULL)
		start->next->cursor_on = 1;
	else if (start->prev != NULL)
		dlist->head->cursor_on = 1;
	else
		return;
	start->cursor_on = 0;
}

void	set_select(t_dlist *dlist)
{
	t_dnode	*start;

	start = dlist->head;
	while(start != NULL && start->cursor_on == 0)
		start = start->next;
	if(start->selected == 0)
		start->selected = 1;
	else
		start->selected = 0;
	go_right(dlist);
}

t_dlist *del_word(t_dlist *dlist)
{
	t_dnode *tmp;
	int i;

	if(dlist->head == NULL)
		return(dlist);
	tmp = dlist->head;
	i = 0;
	while (tmp != NULL && tmp->cursor_on == 0)
	{
		tmp = tmp->next;
		i++;
	}
	if(tmp->next != NULL)
	tmp->next->cursor_on = 1;
	else if(tmp->prev != NULL)
	tmp->prev->cursor_on = 1;
	dlist_deln(dlist, i);
	return(dlist);
}

int	move(char *key, t_dlist *dlist, struct termios old_term, int ttyfd)
{
	char *tmp;
	if (key[0] == 27)
	{
		if (key[2] == 'D')
		{
			go_left(dlist);
			return (1);
		}
		else if (key[2] == 'C')
		{
			go_right(dlist);
			return (1);
		}
		else if (key[1] == 0)
			return(2);
	}
	else if(key[0] == 127)
	{
		dlist = del_word(dlist);
		return(1);
	}
	else if (key[0] == ' ')
	{
		set_select(dlist);
		return (1);
	}
	else if (key[0] == '\n')
	{
		put_dlist(dlist, old_term, ttyfd);
		return (1);
	}
	return (0);
}
