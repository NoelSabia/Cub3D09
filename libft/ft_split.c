/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:35:21 by nsabia            #+#    #+#             */
/*   Updated: 2023/10/24 10:50:55 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	wordcounting(const char *s, char c)
{
	int		counter;
	int		words;

	counter = 0;
	words = 0;
	while (*s != 0)
	{
		if ((!(*s == c)) && (words == 0))
		{
			words = 1;
			counter++;
		}
		else if (*s == c)
			words = 0;
		s++;
	}
	return (counter);
}

static int	malloc_check(char **result, int i)
{
	(void)result;
	(void)i;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	int		word_counter;
	char	**result;
	int		word_length;
	int		i;

	word_counter = wordcounting(s, c);
	result = (char **)ft_calloc(word_counter + 1, sizeof(char *));
	if (!result)
		return (0);
	i = 0;
	while (*s && i < word_counter)
	{
		while (*s == c)
			s++;
		word_length = 0;
		while (s[word_length] && s[word_length] != c)
			word_length++;
		result[i] = ft_substr(s, 0, word_length);
		if (!result[i] && malloc_check(result, i))
			return (0);
		i++;
		s += word_length;
	}
	return (result);
}
