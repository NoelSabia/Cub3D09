/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:03:06 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/07 20:15:33 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	if (str1[0] == 0 && str2[0] == 0)
		return (0);
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else if (str1[i] < str2[i])
			return (-1);
		else if (str1[i] > str2[i])
			return (1);
	}
	return (0);
}
