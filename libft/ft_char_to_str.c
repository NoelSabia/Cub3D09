/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:19:27 by tpaesch           #+#    #+#             */
/*   Updated: 2024/10/21 16:30:15 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_char_to_str(char c)
{
	char	*result;

	result = ft_malloc(2);
	result[0] = c;
	result[1] = '\0';
	return (result);
}
