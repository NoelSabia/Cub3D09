/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:21:24 by tpaesch           #+#    #+#             */
/*   Updated: 2024/09/26 14:03:11 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

bool	ft_strchr_str(char *haystack, char *needle)
{
	int	i;
	int	j;

	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0')
		{
			if (haystack[i] == needle[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}