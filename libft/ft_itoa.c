/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:36:17 by noel              #+#    #+#             */
/*   Updated: 2023/10/24 11:12:51 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"
#include <stdio.h>

static char	*itoa_part1(int n, char *result)
{
	int		i;
	int		minus;

	i = 1;
	minus = 0;
	if (n < 0)
	{
		n *= -1;
		minus++;
	}
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	result = ft_malloc(i + 1 + minus);
	if (!result)
		return (0);
	if (n == 0)
	{
		result[0] = '0';
		result[1] = '\0';
	}
	return (result);
}

static char	*itoa_part3(int n, char *result)
{
	int		i;
	int		m ;
	char	temp[12];

	i = 0;
	m = 0;
	if (n == INT_MIN)
		return (result);
	if (n < 0)
	{
		result[m++] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		temp[i++] = n % 10 + '0';
		n /= 10;
	}
	i--;
	while (i >= 0)
		result[m++] = temp[i--];
	result[m++] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;

	result = 0;
	if (n == INT_MIN)
	{
		result = ft_malloc(12);
		if (!result)
			return (NULL);
		ft_strlcpy(result, "-2147483648", 12);
		return (result);
	}
	if (n == 0)
	{
		result = ft_malloc(2);
		if (!result)
			return (NULL);
		ft_strlcpy(result, "0", 2);
		return (result);
	}
	result = itoa_part1(n, result);
	if (!result)
		return (NULL);
	result = itoa_part3(n, result);
	return (result);
}
