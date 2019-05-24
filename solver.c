/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:17:25 by stherkil          #+#    #+#             */
/*   Updated: 2019/05/23 22:26:03 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	newtab(char ***s, int size)
{
	int i;

	i = -1;
	*s = (char**)malloc(sizeof(char*) * size + 1);

	while (++i < size)
	{

		(*s)[i] = (char*)malloc((sizeof(char) * size + 1));
		ft_memset((*s)[i], '.', size);
		(*s)[i][size] = '\0';
	}
	(*s)[size] = NULL;
}

int		*newlist(int len)
{
	int	i;
	int	*list;

	list = (int*)malloc(sizeof(int) * (len + 1));
	i = -1;
	while (++i < len)
		list[i] = 1;
	list[i] = -1;
	return (list);
}

int		freetab(char ***s)
{
	int i;
	int len;

	len = 0;
	i = 0;
	if (*s == NULL)
		return (0);
	while ((*s)[len] != NULL)
		++len;
	while (i < len)
	{
		ft_bzero((*s)[i], len);
		free((*s)[i]);
		++i;
	}
	free(*s);
	*s = NULL;
	return (0);
}

static int ft_sqrt(int n)
{
	int i;

	i = 2;
	while (i * i < n)
		++i;
	return (i);
}

int		solver(char tetris[28][4][4], int len, char **s)
{
	int		max;
	int		*list;
	int size;
	int i;
	int j;

	i = ft_sqrt(len * 4);
	list = newlist(len);
	newtab(&s, i + 4);
	i = 6;
	while (!backtrack(tetris, s, list, i))
	{
        printf("checked size %d\n", i);
		freetab(&s);
		newtab(&s, i + 4);
		free(list);
		list = newlist(len);
		++i;
	}
	i = -1;
	while (s[++i])
		ft_putendl(s[i]);
	free(list);
	return (0);
}