/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getedges.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:40:48 by stherkil          #+#    #+#             */
/*   Updated: 2019/05/23 14:40:50 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int upper(char s[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (s[i][j] != '.')
				return (i);
	}
	return (0);
}

int lower(char s[4][4])
{
	int i;
	int j;

	i = 4;
	while (--i != 0)
	{
		j = -1;
		while (++j < 4)
			if (s[i][j] != '.')
				return (i);
	}
	return (0);
}

static int lefter(char s[4][4])
{
	int i;
	int j;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
			if (s[i][j] != '.')
				return (j);
	}
	return (0);

}

int righter(char s[4][4])
{
	int i;
	int j;

	j = 4;
	while (--j < 4)
	{
		i = -1;
		while (++i < 4)
			if (s[i][j] != '.')
				return (j);
	}
	return (0);

}

int *getedges(char s[4][4])
{
	int *out;

	if (!(out = malloc(sizeof(int) * 4)))
	return (NULL);
	out[0] = upper(s);
	out[1] = lower(s);
	out[2] = lefter(s);
	out[3] = righter(s);

	return (out);
}
