/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:08:34 by nsabia            #+#    #+#             */
/*   Updated: 2023/10/20 16:42:59 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*destination;

	source = (char *)src;
	destination = (char *)dst;
	if (!source && !destination)
		return (NULL);
	if (source < destination)
	{
		source += len;
		destination += len;
		while (len--)
			*(--destination) = *(--source);
	}
	if (source >= destination)
	{
		while (len--)
			*(destination++) = *(source++);
	}
	return (dst);
}
