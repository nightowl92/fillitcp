/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:28:53 by stherkil          #+#    #+#             */
/*   Updated: 2019/01/24 00:08:24 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	return (a > b ? b : a);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_min(ft_strlen(dst), size);
	len2 = ft_strlen(src);
	if (size > len1 + len2)
		ft_strncat(dst, src, len2 + 1);
	else if (size > len1)
	{
		ft_strncat(dst, src, size - len1 - 1);
		dst[size - 1] = '\0';
	}
	return (len1 + len2);
}
