/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:41:05 by nsabia            #+#    #+#             */
/*   Updated: 2023/10/11 18:43:36 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*g;
	size_t				m;

	g = s;
	m = 0;
	while (m < n)
	{
		if (g[m] == (unsigned char)c)
			return ((void *)(g + m));
		m++;
	}
	return (NULL);
}
