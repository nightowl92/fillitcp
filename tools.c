/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:18:08 by stherkil          #+#    #+#             */
/*   Updated: 2019/05/25 19:42:22 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	to_corner(char s[4][4])
{
	int	i;
	int	j;
	int	*coo;

	i = -1;
	if (!(coo = getedges(s)))
		return (0);
	if (coo[0] == 0 && coo[2] == 0)
	{
		free(coo);
		return (1);
	}
	while (++i <= coo[1] - coo[0])
	{
		j = -1;
		while (++j <= coo[3] - coo[2])
		{
			s[i][j] = s[coo[0] + i][coo[2] + j];
			s[coo[0] + i][coo[2] + j] = '.';
		}
	}
	free(coo);
	return (1);
}
