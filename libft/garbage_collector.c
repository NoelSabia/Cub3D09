/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:11:49 by nsabia            #+#    #+#             */
/*   Updated: 2024/09/26 16:01:13 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	*garbage_col_count(void)
{
	static int	count = 0;

	return (&count);
}

int	*garbage_col_size(void)
{
	static int	count = GARBAGE_COL_SIZE;

	return (&count);
}

void	***garbage_col_get(void)
{
	static void	**garbage = NULL;

	return (&garbage);
}

int	ft_garbage_col_create(void)
{
	void	***garbage;

	garbage = garbage_col_get();
	if (*garbage)
		return (1);
	*garbage_col_count() = 0;
	*garbage = malloc(sizeof(void *) * GARBAGE_COL_SIZE);
	if (!*(garbage))
		return (0);
	return (1);
}

int	ft_garbage_col_add(void *ptr)
{
	void	***garbage;
	void	**new_garbage;
	int		*count;

	garbage = garbage_col_get();
	if (!*garbage && !ft_garbage_col_create())
		return (GARBAGE_ERROR_CREATE);
	count = garbage_col_count();
	if (*count >= *garbage_col_size())
	{
		new_garbage = malloc(sizeof(void *) * (*garbage_col_size() * 2));
		if (!new_garbage)
			return (GARBAGE_ERROR_EXPAND);
		ft_memcpy(new_garbage, *garbage, sizeof(void *)
			* (*garbage_col_count()));
		free(*garbage);
		*garbage = new_garbage;
		*garbage_col_size() *= 2;
	}
	(*garbage)[(*count)++] = ptr;
	return (GARBAGE_SUCCESS);
}
