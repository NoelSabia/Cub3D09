/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:05:55 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/05 15:15:53 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char	*newptr;

	if (!ptr)
		return (ft_malloc(new_size));
	newptr = ft_malloc(new_size);
	if (!newptr)
		return (ptr);
	ft_memcpy(newptr, ptr, old_size);
	return (newptr);
}
