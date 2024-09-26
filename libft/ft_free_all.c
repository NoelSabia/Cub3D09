/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:47:12 by tpaesch           #+#    #+#             */
/*   Updated: 2024/09/26 15:48:44 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_all(void)
{
	void	***garbage;
	int		*count;
	int		i;

	garbage = garbage_col_get();
	if (!*garbage)
		return ;
	count = garbage_col_count();
	i = 0;
	while (i < *count)
	{
		free((*garbage)[i]);
		(*garbage)[i] = NULL;
		i++;
	}
	free(*garbage);
	*garbage = NULL;
	*count = 0;
}
