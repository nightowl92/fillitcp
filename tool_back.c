/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:40:08 by stherkil          #+#    #+#             */
/*   Updated: 2019/05/27 13:33:50 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**cpytab(char **s)
{
	int		i;
	int		j;
	int		size;
	char	**new;

	i = -1;
	size = -1;
	while (s[++size] != NULL)
		;
	new = newtab(size);
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
			new[i][j] = s[i][j];
	}
	return (new);
}

int		*cpylist(int *list)
{
	int	*new;
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

int		ft_sqrt(int n)
{
	int i;

	i = 2;
	while (i * i < n)
		++i;
	return (i);
}

char	getletter(char s[4][4])
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (s[i][j] != '.')
				return (s[i][j]);
	}
	return (0);
}
