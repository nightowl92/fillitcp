/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:17:15 by stherkil          #+#    #+#             */
/*   Updated: 2019/05/22 22:00:03 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H_
# define _FILLIT_H_

#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv);
int parser(char buf[544], int buflen);
int algo(char tetri[28][4][4], int len);
int *getedges(char s[4][4]);
char **solver(char tetris[28][4][4], int len);
int ft_try(char tetris[28][4][4], int len, char	***s);
int	to_corner(char s[4][4]);
void    printresult(int max, char **s);
int		freetab(char ***s);
int righter(char s[4][4]);
int lower(char s[4][4]);

# endif