/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:59:38 by nsabia            #+#    #+#             */
/*   Updated: 2023/10/13 14:47:09 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	m;

	i = 0;
	m = 0;
	while (dst[i] != 0 && i < size)
		i++;
	while (src[m] != 0 && i + m + 1 < size)
	{
		dst[i + m] = src[m];
		m++;
	}
	if (i < size)
	{
		dst[i + m] = '\0';
	}
	return (ft_strlen(src) + i);
}
