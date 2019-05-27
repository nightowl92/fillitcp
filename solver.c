/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:17:25 by stherkil          #+#    #+#             */
/*   Updated: 2019/05/27 13:29:59 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				printresult(char **s, int i)
{
	int j;
	int max;

	max = 0;
	while (s[++i] != NULL)
	{
		j = -1;
		while (s[i][++j])
		{
			if (s[i][j] != '.' && s[i][j] != '\n')
			{
				if (i > j && i > max)
					max = i;
				if (j >= i && j > max)
					max = j;
			}
		}
	}
	i = -1;
	while (++i <= max)
	{
		write(1, s[i], max + 1);
		write(1, "\n", 1);
	}
}

char				**newtab(int size)
{
	int		i;
	char	**s;

	i = -1;
	if (!(s = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (++i < size)
	{
		s[i] = ft_strnew(size);
		ft_memset(s[i], '.', size);
		s[i][size] = '\0';
	}
	s[size] = NULL;
	return (s);
}

int					*newlist(int len)
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

void				freetab(char **s)
{
	int i;

	i = -1;
	if (s)
	{
		while (s[++i] != 0)
			ft_memdel((void**)&(s[i]));
		free(s);
		s = NULL;
	}
}

int					solver(char tetris[28][4][4], int len, char **s)
{
	int		max;
	int		*list;
	int		i;

	i = ft_sqrt(len * 4);
	max = ft_sqrt(len * 4);
	printf("max %d\n", max);
	while (1)
	{
		if (!(s = newtab(i + 4)))
			return (0);
		list = newlist(len);
		if (backtrack(tetris, s, list, max) == 1)
			break ;
		freetab(s);
		free(list);
		++max;
		++i;
	}
	printresult(s, -1);
	freetab(s);
	free(list);
	return (1);
}
