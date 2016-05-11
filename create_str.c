/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 13:26:26 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/05/08 15:57:25 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	put_dlist(t_dlist *dlist, struct termios old_term, int ttyfd)
{
	t_dnode	*head;
	char	*str;

	head = dlist->head;
	str = ft_strnew(1);
	while(head != NULL)
	{
		if(head->selected == 1)
		{
		
			str = ft_stradd(str, head->data);
			str = ft_stradd(str, " ");
		}
		head = head->next;
	}
	ft_putendl(str);
	quit(old_term);
}
