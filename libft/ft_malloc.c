/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:49:19 by tpaesch           #+#    #+#             */
/*   Updated: 2024/09/26 15:49:47 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size)
{
	void	*ptr;
	int		err;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	err = ft_garbage_col_add(ptr);
	if (err == GARBAGE_ERROR_EXPAND)
	{
		ft_free_all();
		free(ptr);
		return (NULL);
	}
	else if (err == GARBAGE_ERROR_CREATE)
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}
