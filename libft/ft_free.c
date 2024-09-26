/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:14:27 by tpaesch           #+#    #+#             */
/*   Updated: 2024/09/26 15:15:19 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(void *ptr)
{
	void	***garbage;
	int		i;
	int		j;

	i = -1;
	if (ptr == NULL)
		return ;
	garbage = garbage_col_get();
	while (++i < *garbage_col_count())
	{
		if ((*garbage)[i] == ptr)
		{
			j = i - 1;
			while (++j < *garbage_col_count() - 1)
				(*garbage)[j] = (*garbage)[j + 1];
			(*garbage_col_count())--;
			free(ptr);
			break ;
		}
	}
}
