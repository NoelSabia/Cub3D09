/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_str_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:50:00 by tpaesch           #+#    #+#             */
/*   Updated: 2024/09/26 15:56:46 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	tp_malloc(size_t size, void **ptr)
{
	*ptr = ft_malloc(size);
	return (*ptr == NULL);
}

bool	ft_malloc_str_arr(size_t size, char ***arr)
{
	if (tp_malloc((size + 1) * sizeof(char *), (void **) arr))
		return (false);
	(*arr)[size] = NULL;
	return (true);
}
