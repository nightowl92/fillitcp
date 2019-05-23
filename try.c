/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 23:11:03 by stherkil          #+#    #+#             */
/*   Updated: 2019/05/23 14:01:22 by stherkil         ###   ########.fr       */
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
	{
		list[i] = 1;
	}
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
		ft_memset((*s)[i], '.', size);
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

	i = -1;
	if ((n + lower(in) + 1 > max2) || (m + righter(in) + 1 > max2))
		return (0);
	while (++i <= lower(in))
	{
		j= -1;
		while (++j <= righter(in))
			if ((s[i + n][j + m] != '.') && in[i][j] != '.')
				return (0);
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

int		fit(char **s, char ttr[4][4], int n, int flag)
{
	int i;
	int j;

	i = -1;
	while (++i < 544)
	{
		j= -1;
		while (++j < 544)
		{
			if (checktab(s, ttr, i, j, n))
			{
				if (flag == 1)
					addtab(s, ttr,i,j);
				return (1);
			}
		}
	}
	return (0);
}

void		printbuf(int max, char s[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			write(1, s[i] + j, 1);
		}
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
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

int		isemp(int *list)
{
	int i;

	i = -1;
	while (list[++i] != -1)
	{
		if (list[i] == 1)
		return (0);
	}
	return (1);
}

int *rmpos(int *list, int pos)
{
	int *out;

	if (!(out = cpylist(list)))
		return (NULL);
	out[pos] = 0;
	return(out);
}

int		backtrack(char tetris[28][4][4], char ***s, int *list, int max)
{
	char **tmps;
	int i = -1;

	if (isemp(list))
		return (1);
	tmps = cpytab(*s);
	while (list[++i] != -1)
	{
		if (list[i] > 0)
		{
			list[i] = 0;
			if (fit(*s, tetris[i], max, 1))
			{
				fit(*s, tetris[i], max, 0);
				list = cpylist(list);
				if (backtrack(tetris, s, rmpos(list, i), max))
				{
					freetab(&tmps);
					return (1);
				}
				else
				{
					freetab(s);
					*s = cpytab(tmps);
				}
			}
			list[i] = 1;
		}
	}
	freetab(&tmps);
	return (0);
}

int ft_sqrt(int n)
{
	int i;

	i = 0;
	while (i * i < n)
	++i;
return (i);
}

int		ft_try(char tetris[28][4][4], int len, char ***s)
{
	int		max;
	int		*list;
	int size;
	int i;

	i = ft_sqrt(len * 4);
	list = newlist(len + 4);
	newtab(s, len + 4);
	while (!(size = backtrack(tetris, s, list, i)))
	{
		freetab(s);
		newtab(s,  len + 4);
		free(list);
		list = newlist(len);
		++i;
	}
	free(list);
	return (0);
}