/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 13:18:26 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/05/09 14:33:37 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_max_word(t_dlist *dlist)
{
	int max_len;
	t_dnode *head;

	max_len = 0;
	head = dlist->head;
	while (head != NULL)
	{
		if(ft_strlen(head->data) > max_len)
			max_len = ft_strlen(head->data);
		head = head->next;
	}
	return (max_len);
}

void	print_word(t_dnode *tmp, int ttyfd)
{
	if(tmp->cursor_on == 1)
	tputs(tgetstr("us", NULL), 1, ft_putchar2);
	if(tmp->selected == 1)
	tputs(tgetstr("so", NULL), 1, ft_putchar2);
	ft_putstr_fd(tmp->data, ttyfd);
	if(tmp->selected == 1)
	tputs(tgetstr("me", NULL), 1, ft_putchar2);
	if(tmp->cursor_on == 1)
	tputs(tgetstr("ue", NULL), 1, ft_putchar2);
}

void	get_home_pos(int nb_line)
{
	int i;
	char *tmp;

	tmp = NULL;
	i = 0;
	tmp = tgetstr("up", NULL);
	tputs(tgetstr("cr", NULL), 1, ft_putchar2);
	while (i < nb_line)
	{
		tputs(tmp, 1, ft_putchar2);
		i++;
	}
}

int	show_menu(t_dlist *dlist, int nb_col, int ttyfd)
{
	int		i;
	int		nb_word_col;
	int		word_max;
	int		j;
	t_dnode	*tmp;
	char *tmp2;

	if (dlist->head == NULL)
		return(-1);
	word_max = get_max_word(dlist) + 1;
	tputs(tgetstr("cd", NULL), tgetnum("co"), ft_putchar2);
	nb_word_col = tgetnum("co") / word_max;
	 i = 0;
	 tmp = dlist->head;
	while(tmp != NULL)
	{
		j = 0;
		print_word(tmp, ttyfd);
		if((i + 1) % nb_word_col == 0 && (i + 1) != 0)
		{
			ft_putchar_fd('\n', ttyfd);
			nb_col++;
		}
		else
		{
			while(ft_strlen(tmp->data) + j < word_max)
			{
				ft_putchar_fd(' ', ttyfd);
				j++;
			}
		}
		i++;
		tmp = tmp->next;
	}
	get_home_pos(dlist->size / nb_word_col);
	return (nb_col);
}
