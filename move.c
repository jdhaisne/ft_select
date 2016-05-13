/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 12:42:06 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/05/13 16:18:42 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	go_up(t_dlist *dlist, int nb_word_line)
{
	t_dnode *start;
	int i;

	i = 0;
	start = dlist->head;
	while(start != NULL && start->cursor_on == 0)
	{
		start = start->next;
		i++;
	}
	start->cursor_on = 0;
	start = dlist_goto(dlist, i - nb_word_line);
	start->cursor_on = 1;
}

void	go_down(t_dlist *dlist, int nb_word_line)
{
	t_dnode *start;
	int i;

	i = 0;
	start = dlist->head;
	while(start != NULL && start->cursor_on == 0)
	{
		start = start->next;
		i++;
	}
	start->cursor_on = 0;
	if(i + 5 > (int)dlist->size)
		nb_word_line -= 1;
	start = dlist_goto(dlist, i + nb_word_line);
	start->cursor_on = 1;
}

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

	if(dlist == NULL)
		return(NULL);
	tmp = dlist->head;
	i = 0;
	while (tmp->next != NULL && tmp->cursor_on == 0)
	{
		tmp = tmp->next;
		i++;
	}
	if(tmp->next != NULL)
	tmp->next->cursor_on = 1;
	else if(tmp->prev != NULL && tmp->prev != NULL)
	tmp->prev->cursor_on = 1;
		ft_putendl("G1");
	dlist_deln(dlist, i);
		ft_putendl("G2");
	if (dlist->head == NULL)
			return(NULL);
	return(dlist);
}

int	move(char *key, t_data *data)
{
	if (key[0] == 27)
	{
		if (key[2] == 'D')
		{
			go_left(data->dlist);
			return (1);
		}
		else if(key[2] == 'A')
		{
			go_up(data->dlist, data->nb_word_line);
			return (1);
		}
		else if (key[2] == 'C')
		{
			go_right(data->dlist);
			return (1);
		}
		else if (key[2] == 'B')
		{
			go_down(data->dlist, data->nb_word_line);
			return (1);
		}
		else if (key[1] == 0)
			return(2);
	}
	else if(key[0] == 127)
	{
		ft_putendl("D1");
		data->dlist = del_word(data->dlist);
		ft_putendl("D2");
		return(1);
	}
	else if (key[0] == ' ')
	{
		set_select(data->dlist);
		return (1);
	}
	else if (key[0] == '\n')
	{
		put_dlist(data->dlist, data->old_term);
		return (1);
	}
	return (0);
}
