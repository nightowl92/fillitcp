/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 23:11:03 by stherkil          #+#    #+#             */
/*   Updated: 2019/05/21 12:24:18 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*newlist(int len)
{
	int	i;
	int	*list;

	list = (int*)malloc(sizeof(int) * (len + 1));
	i = -1;
	while (++i < len)
		list[i] = i;
	list[i] = -1;
	return (list);
}

void	newtab(char ***s, int size)
{
	int i;

	i = -1;
	*s = (char**)malloc(sizeof(char*) * size + 1);
	while (++i < size)
	{
		(*s)[i] = (char*)malloc((sizeof(char) * size + 1));
		ft_memset((*s)[i], '.', size - 1);
		(*s)[i][size - 1] = '\0';
	}
	(*s)[size] = NULL;
}

int		sqtablen(char **s)
{
	int i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

char	**cpytab(char **s)
{
	int i;
	int j;
	int size;
	char **new;

	i = -1;
	size = sqtablen(s);
	newtab(&new, size);
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
			new[i][j] = s[i][j];
	}
	return (new);
}

int		checktab(char **s, char in[4][4], int n, int m, int max2)
{
	int i;
	int j;
	int max1;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (s[i + n][j + m] != '.' && in[i][j] != '.')
				return (0);
			if (s[i + n][j + m] == '.')
			{	
				if (i + n > j + m)
					max1 = i + n;
				else
					max1 = j + m;
				if (max1 > max2)
					return (0);
			}
		}
	}
	return (1);
}

char	**addtab(char **s, char in[4][4], int n, int m)
{
	int i;
	int j;
	int max;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (s[i + n][j + m] == '.')
			{
				s[i + n][j + m] = in[i][j];
				if (i + n > j + m)
					max = i + n;
				else
					max = j + m;
			}
		}
	}
	return (s);
}

int		fit(char **s, char ttr[4][4], int n)
{
	int i;
	int j;
	i = -1;
	while (++i < 6)
	{
		j= -1;
		while (++j < 6)
			if (checktab(s, ttr,i, j, n))
			{
				addtab(s, ttr,i,j);
				return (1);
			}
	}
	return (0);
}

int		get_next(int *list)
{
	int i;

	i = -1;
	while (++i >= 0)
	{
		if (list[i] != -2)
			return (list[i]);
	}
	return (-1);
}

int		*cpylist(int *list)
{
	int	*new;
	int len;
	int i;

	i = -1;
	while (list[++i] != -1)
		;
	new = (int*)malloc(sizeof(int) * (i + 1));
	i = -1;
	while (list[++i] != -1)
		new[i] = list[i];
	new[i] = -1;
	return (new);
}

int		freetab(char ***s)
{
	int i;
	int len;

	len = -1;
	i = -1;
	while ((*s)[++len] != NULL)
		;
	while ((*s)[++i] != NULL)
	{
		ft_bzero((*s)[i], len);
		free((*s)[i]);
	}
	free(*s);
	return (0);
}

int		backtrack(char tetris[28][4][4], char ***s, int *list, int max)
{
	int ret;
	char **tmps;
	int *tmpl;

if (get_next(list) == -1)
		return (1);
	tmpl = cpylist(list);
	while((ret = get_next(tmpl)) != -1)
	{
		tmpl[ret] = -2;
		tmps = cpytab(*s);
		if (fit(*s, tetris[ret], max))
		{
			list[ret] = -2;
			if (backtrack(tetris, s, list, max))
				return (1);
			else
				list[ret] = ret;
			
		}
		freetab(s);
		*s = cpytab(tmps);
		freetab(&tmps);
	}
	free(tmpl);
	return (0);
}

int		ft_try(char tetris[28][4][4], int len, char ***s)
{
	int		max;
	int		*list;

	max = 4;
	list = newlist(3);
	newtab(s, len * 2);
	while(!backtrack(tetris, s, list, ++max))
	;
	return (0);
}