/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 11:43:10 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/05/11 13:03:09 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	dlist_del(t_dlist **dlist)
{
	t_dnode *tmp1;
	t_dnode *tmp2;

	if(*dlist != NULL)
	{
		tmp1 = (*dlist)->head;
		while (tmp1 != NULL)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
			ft_strdel(&(tmp2->data));
			free(tmp2);
		}
		free(*dlist);
		dlist = NULL;
	}
}

t_dlist	*dnode_del(t_dlist *dlist, t_dnode *tmp)
{
	if(tmp->prev != NULL && tmp->next == NULL)
	{
		tmp->prev->next = NULL;
		dlist->tail = tmp->prev;
	}
	else if (tmp->next != NULL && tmp->prev == NULL)
	{
		tmp->next->prev = NULL;
		dlist->head = tmp->next;
	}
	else if (tmp->prev == NULL && tmp->next == NULL)
	{
	free(tmp);
		free(dlist);
			return(NULL);
	}
	else 
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}
	free(tmp);
	dlist->size--;
	return (dlist);
}

t_dlist	*dlist_deln(t_dlist *dlist, int n)
{
	int i;
	t_dnode *tmp;

	i = 0;
	tmp = dlist->head;
	while(tmp != NULL && i <= n)
	{
		if (i == n)
			dlist = dnode_del(dlist, tmp);
		else
			tmp = tmp->next;
		i++;
	}
	return (dlist);
}

t_dlist	*dlist_new()
{
	t_dlist	*dlist;

	dlist = ft_memalloc(sizeof(t_dlist));
	if (dlist != NULL)
	{
		dlist->size = 0;
		dlist->head = NULL;
		dlist->tail = NULL;
	}
	return (dlist);
}

t_dnode	*dnode_new(char *data)
{
	t_dnode	*new;

	new = NULL;
	new = ft_memalloc(sizeof(t_dnode));
	if(new != NULL)
	{
		new->data = ft_strdup(data);
		new->selected = 0;
		new->cursor_on = 0;
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

t_dlist	*dlist_addtail(t_dlist *dlist, char *data)
{
	t_dnode *new;

	if (dlist != NULL)
	{
		if ((new = dnode_new(data)) != NULL)
		{
			if(dlist->tail == NULL)
			{
				dlist->head = new;
				dlist->tail = new;
				new->cursor_on = 1;
			}
			else
			{
				dlist->tail->next = new;
				new->prev = dlist->tail;
				dlist->tail = new;
			}
			dlist->size++;
		}
	}
	return (dlist);
}

t_dlist	*dlist_addhead(t_dlist *dlist, char *data)
{
	t_dnode *new;

	if (dlist != NULL)
	{
		if ((new = dnode_new(data)) != NULL)
		{
			if(dlist->tail == NULL)
			{
				dlist->head = new;
				dlist->tail = new;
			}
			else
			{
				dlist->head->prev = new;
				new->next = dlist->head;
				dlist->head = new;
			}
			dlist->size++;
		}
	}
	return (dlist);
}
