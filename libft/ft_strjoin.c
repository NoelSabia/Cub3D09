/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:21:26 by noel              #+#    #+#             */
/*   Updated: 2023/10/21 18:17:34 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	sum;

	sum = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = ft_malloc(sum);
	if (!s3)
		return (NULL);
	ft_memset(s3, 0, sum);
	ft_strlcpy(s3, s1, sum + 1);
	ft_strlcat(s3, s2, sum + 1);
	return (s3);
}
