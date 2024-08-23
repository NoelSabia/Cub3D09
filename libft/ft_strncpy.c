/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:39:00 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/07 20:29:10 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *src, int start, int end)
{
	char	*result;
	int		length;
	int		i;

	if (src == NULL || start < 0 || end < start || src[start] == '\0')
		return (NULL);
	length = end - start + 1;
	result = ft_malloc(length + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (start <= end && src[start] != '\0')
		result[i++] = src[start++];
	result[i] = '\0';
	return (result);
}
