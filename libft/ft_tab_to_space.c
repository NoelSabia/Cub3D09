/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:02:16 by tpaesch           #+#    #+#             */
/*   Updated: 2024/09/23 15:37:21 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tab_to_space(const char *str, char *result)
{
	const char	*replacement;
	int i;
	int j;

	i = -1;
	j = -1;
	replacement = "    ";
	while (str[++(i)])
	{
		if (str[i] == '\t')
		{
			ft_memcpy(&result[j + 1], replacement, 4);
			j += 4;
		}
		else
			result[++(j)] = str[i];
	}
	result[j + 1] = '\0';
	return (result);
}
