/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 19:07:32 by stherkil          #+#    #+#             */
/*   Updated: 2019/05/22 12:40:36 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_error(void)
{
	printf("out");
	return (0);
}

static int		ft_checklen(ssize_t nb)
{
	if (nb > 544 || nb < 19 || ((((nb - 19) % 21) > 0)))
		return (1);
	return (0);
}

void		printresult(int max, char **s)
{
	int i;
	int j;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (s[i][++j])
		{
			write(1, s[i] + j, 1);
		}
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

static void		buftotab(char tetris[28][4][4],
		char buf[545], int buflen, int ct)
{
	int i;
	int j;

	while (buflen && *buf)
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
			{
				if (*buf != '.')
					tetris[ct][i][j] = ct + 'A';
				else
					tetris[ct][i][j] = *buf;
				--buflen;
				buf++;
			}
			buf++;
			--buflen;
		}
		buf++;
		++ct;
	}
}

int				puttocorn(char tetris[28][4][4], int bufsize)
{
	int len;
	int i;

	len = 1;
	bufsize -= 19;
	i = -1;
	while (bufsize > 0)
	{
		bufsize -= 21;
		++len;
	}
	while (++i < len)
		to_corner(tetris[i]);
	return (len);
}

int				main(int argc, char **argv)
{
	int		buflen;
	char	buf[545];
	char	tetris[28][4][4];
	int		fd;
	char	**s;
	int cal;

	fd = open(argv[1], O_RDONLY);
	if (ft_checklen((buflen = read(fd, buf, 546))))
		return (ft_error());
	if (!(cal = parser(buf, buflen)))
	{
		printf("return %d\n", cal);
		return (ft_error());
		}
		printf("return %d\n", cal);
		/*
	buftotab(tetris, buf, buflen, 0);
	printresult(ft_try(tetris, puttocorn(tetris, buflen), &s), s);*/
	return (0);
}
