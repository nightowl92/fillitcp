/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 19:08:39 by stherkil          #+#    #+#             */
/*   Updated: 2019/05/27 14:00:11 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		down(char buf[544], int xfirst)
{
	if ((buf[xfirst + 5 + 1] == '#' && buf[xfirst + 5 + 1 + 1] == '#')
			|| (buf[xfirst + 5 + 1] == '#'
				&& buf[xfirst + 5 + 1 + 5] == '#')
			|| (buf[xfirst + 5 + 5] == '#'
				&& buf[xfirst + 5 + 5 + 1] == '#')
			|| (buf[xfirst + 5 + 5] == '#'
				&& buf[xfirst + 5 + 5 + 5] == '#')
			|| (buf[xfirst + 5 - 1] == '#'
				&& buf[xfirst + 5 - 1 + 5] == '#')
			|| (buf[xfirst + 5 - 1] == '#'
				&& buf[xfirst + 5 + 1] == '#')
			|| (buf[xfirst + 5 - 1] == '#'
				&& buf[xfirst + 5 + 5] == '#')
			|| (buf[xfirst + 5 + 1] == '#'
				&& buf[xfirst + 5 + 5] == '#'))
		return (1);
	return (0);
}

static int		checkbasic(char buf[544], int xfirst, int xlast)
{
	if ((buf[xfirst + 1] == '#' && buf[xfirst + 5] == '#'))
		if (buf[xfirst + 2] == '#' || buf[xfirst + 4] == '#'
				|| buf[xfirst + 10] == '#' || buf[xfirst + 6] == '#')
			return (1);
	if (buf[xlast - 1] == '#' && buf[xlast - 5] == '#')
		if (buf[xlast - 2] == '#' || buf[xlast - 4] == '#'
				|| buf[xlast - 10] == '#')
			return (1);
	if (buf[xfirst + 1] == '#')
	{
		if (((buf[xfirst + 1 + 1] == '#')
					&& (buf[xfirst + 1 + 1 + 1] == '#'
						|| buf[xfirst + 1 + 1 + 5] == '#'
						|| buf[xfirst + 1 + 5] == '#'))
				|| ((buf[xfirst + 1 + 5] == '#')
					&& (buf[xfirst + 1 + 5 + 1] == '#'
						|| buf[xfirst + 1 + 5 + 5] == '#')))
			return (1);
	}
	else if (buf[xfirst + 5] == '#')
		if (down(buf, xfirst))
			return (1);
	return (0);
}

static int		checkfig(char buf[544])
{
	int xfirst;
	int xlast;
	int i;

	i = -1;
	while (++i < 19)
		if (buf[i] == '#')
			break ;
	xfirst = i;
	while (++i < 19)
		if (buf[i] == '#')
			xlast = i;
	if (checkbasic(buf, xfirst, xlast))
		return (1);
	printf("%d %d \n", xfirst, xlast);
	return (0);
}

static int		checktetri(char buf[544], int buflen, int diez)
{
	int i;
	int j;

	i = -1;
	while (++i < 4 && buflen >= 0)
	{
		j = -1;
		while (++j < 4 && --buflen >= 0)
		{
			if (buf[i * 5 + j] != '.' && buf[i * 5 + j] != '#')
				return (0);
			if (buf[i * 5 + j] == '#')
				++diez;
		}
		if (buflen == 0)
			break ;
		buflen--;
		if (i != 3)
			if (buf[i * 5 + j] != '\n')
				return (0);
	}
	if (diez != 4)
		return (0);
	return (1);
}

int				parser(char buf[544], int buflen)
{
	int i;
	int len;

	len = 0;
	i = 0;
	if (((buflen - 19) % 21) != 0)
		return (0);
	while (buflen - i > 0)
	{
		if (!checktetri(buf + i, 19, 0))
			return (0);
		if (!checkfig(buf + i))
			return (0);
		len += 1;
		i += 19;
		if (buflen - i == 0)
			return (len);
		if (buf[i] == '\n' && buf[i + 1] == '\n')
			i += 2;
		else
			return (0);
	}
	return (len);
}
