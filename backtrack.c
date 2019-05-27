/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 19:01:33 by stherkil          #+#    #+#             */
/*   Updated: 2019/05/27 13:33:30 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				checktab(char **s, char in[4][4], int n[2], int max2)
{
	int i;
	int j;

	i = -1;
	if ((n[0] + lower(in) + 1 > max2) || (n[1] + righter(in) + 1 > max2))
		return (0);
	while (++i <= lower(in))
	{
		j = -1;
		while (++j <= righter(in))
			if ((s[i + n[0]][j + n[1]] != '.') && in[i][j] != '.')
				return (0);
	}
	addtab(s, in, n[0], n[1]);
	return (1);
}

static int		isemp(int *list)
{
	int i;

	i = -1;
	while (list[++i] != -1)
		if (list[i] == 1)
			return (0);
	return (1);
}

static void		remtab(char ***s, char a)
{
	int i;
	int j;

	i = -1;
	while ((*s)[++i] != NULL)
	{
		j = -1;
		while ((*s)[i][++j])
			if ((*s)[i][j] == a)
				(*s)[i][j] = '.';
	}
}

static void		repl(char ttr[28][4][4], char **s, int *list, int n)
{
	list[n] = 1;
	remtab(&s, getletter(ttr[n]));
}

int				backtrack(char ttr[28][4][4], char **s, int *list, int max)
{
	int i[2];
	int n;

	n = -1;
	if (isemp(list))
		return (1);
	while (list[++n] != -1)
	{
		if (list[n] && (i[0] = -1) == -1)
		{
			while (++i[0] < max && s[i[0]] != NULL && (i[1] = -1) == -1)
			{
				while (++i[1] < max && s[i[0]][i[1]])
				{
					if (checktab(s, ttr[n], i, max))
					{
						if (!(list[n] = 0) && backtrack(ttr, s, list, max))
							return (1);
						repl(ttr, s, list, n);
					}
				}
			}
		}
	}
	return (0);
}
