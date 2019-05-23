#include "fillit.h"
/*
   static void		buftotab(char tetris[28][4][4], char buf[545], int buflen)
   {
   int ct;
   int i;
   int j;
   ​
   ct = 0;
   while (buflen && *buf)
   {
   i = -1;
   while (++i < 4)
   {
   j = -1;
   while(++j < 4)
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
   ​
   static int		terminos_valide(char **str)
   {
   int i;
   int j;
   int c;
   int bloc;
   ​
   i = 0;
   c = 0;
   bloc = 0;
   while (*str)
   {
   if (i > 3)
   return (error);
   j = 0;
   while (str[i][j] != '\n')
   {
   if (str == NULL || str[i][j] != '.' || str[i][j] != '#' || j > 3)
   return (error);
   if (str[i][j] == '.' || str[i][j] == '#')
   c++;
   if (str[i][j] == '#')
   bloc++;
   j++;
   }
   i++;
   }
   if (c != 16 || bloc != 4)
   return (error);
   return (1);
   }
   ​
   static int		check_fusion_bloc(char **str)
   {
   int i;
   int j
   int fus_Y;
   int fus_X;
   ​
   fus_Y = 0;
fus_X = 0;
i = 0;
while ( str[i][0] != '\n')
{
	j = 0
		while (str[i][j] != '\n')
		{
			if str[i][j] == '#'
			{
				if (i - 1 >=0 && str[i -1][j] == '#')
					fus_Y++;
				if (i + 1 < 4 && str[i + 1][j] == '#')
					fus_Y++;
				if (j - 1 >=0 && str[i][j - 1] == '#')
					fus_X++;
				if (j + 1 < 4 && str[i][j + 1] == '#')
					fus_X++;
			}
			j++;
		}
	i++;
}
if( (fus_Y == 0 && fus_X == 6) || (fus_Y == 6 && fus_X == 0))
	return (1);
if( (fus_Y - fus_X) == 0)
	return (1);
	return (error);
	}
​*/

int checktetri(char buf[544], int buflen)
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
		}
		if (buflen == 0)
			break;
		buflen--;
		if (buf[i * 5 + j] != '\n')
			return (0);
	}
	return (1);
}
int parser(char buf[544], int buflen)
{
	int i;
	int len;

	len = 0;
	i = 0;
	while (buflen - i > 0)
	{
		if (!checktetri(buf + i, 19))
			return (0);
		len += 1;
		i += 20;
		if (buflen - i <= 0)
			return (len);
		if (buf[i] != '\n')
			return (0);
		++i;
	}
	return (len);
}
