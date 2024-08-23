/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:24:32 by nsabia            #+#    #+#             */
/*   Updated: 2023/10/22 12:19:20 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;
	size_t				i;

	i = 0;
	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	while (i < n)
	{
		if (a[i] == b[i])
			i++;
		else if (a[i] < b[i])
			return (a[i] - b[i]);
		else if (a[i] > b[i])
			return (a[i] - b[i]);
	}
	return (0);
}
