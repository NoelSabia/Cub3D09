/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:03:22 by nsabia            #+#    #+#             */
/*   Updated: 2023/10/20 13:24:12 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last_occ;

	last_occ = 0;
	while (*str != 0)
	{
		if (*str == (char)c)
			last_occ = (char *)str;
		str++;
	}
	if ((char) c == 0)
		return ((char *)str);
	return (last_occ);
}
