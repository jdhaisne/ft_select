/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:49:51 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/05/09 12:55:45 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int ft_putchar2(int i)
{
	int ttyfd;

	ft_putchar_fd(i, 2);
	return (i);
}

char	**split_tab(char **tab, int i)
{
	int		size;
	int		j;
	char	**tab2;

	size = 0;
	j = 0;
	tab2 = NULL;
	while (tab[i + size] != NULL)
		size++;
	tab2 = (char **)ft_memalloc(sizeof(char *) * size + 1);
	while (j < size)
	{
		tab2[j] = strdup(tab[i + j]);
		j++;
	}
	tab2[size] = NULL;
	return (tab2);
}

char *get_key()
{
	char *line;
	line = ft_strnew(3);
	read(0, line, 3);
	return(line);
}
