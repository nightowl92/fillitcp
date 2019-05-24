#include "fillit.h"

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

static int		isemp(int *list)
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

static int *rmpos(int *list, int pos)
{
	int *out;

	if (!(out = cpylist(list)))
		return (NULL);
	out[pos] = 0;
	return(out);
}

static char		fit(char **s, char ttr[4][4], int n, int flag)
{
	int i;
	int j;

	while (++i < n)
	{
		j = -1;
		while (++j < n)
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

static char getletter(char s[4][4])
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

static void remtab(char ***s, char a)
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

int backtrack(char ttr[28][4][4], char **s, int *list, int max)
{
	int i;
	int j;
	int n;
	int m;

	n = -1;
	if (isemp(list))
		return (1);
	while (list[++n] != -1)
	{
		if (list[n])
		{
			i = -1;
			while (++i < max && s[i] != NULL)
			{
				j = -1;
				while (++j < max && s[i][j])
				{
					if (checktab(s, ttr[n], i, j, max))
					{
						addtab(s, ttr[n],i, j);
						if (backtrack(ttr, s, rmpos(list, n), max))
							return (1);
						else
							remtab(&s, getletter(ttr[n]));
					}
				}
			}
		}
	}
	return (0);
}