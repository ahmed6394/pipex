/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:05:37 by gahmed            #+#    #+#             */
/*   Updated: 2024/10/13 17:58:50 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char delimiter)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != delimiter && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == delimiter)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*copy_word(const char *start, int length)
{
	char	*word;
	int		i;

	word = malloc(length + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < length && start[i] != '\0')
	{
		word[i] = start[i];
		i++;
	}
	while (i < length)
	{
		word[i] = '\0';
		i++;
	}
	word[length] = '\0';
	return (word);
}

static void	free_mem(char **result, int i)
{
	while (i > 0)
		free(result[--i]);
	free(result);
}

static char	**fill_words(const char *s, char delimiter, char **result)
{
	int			i;
	const char	*start;

	i = 0;
	while (*s)
	{
		while (*s == delimiter)
			s++;
		if (*s)
		{
			start = s;
			while (*s && *s != delimiter)
				s++;
			result[i] = copy_word(start, (s - start));
			if (!result[i])
			{
				free_mem(result, i);
				return (NULL);
			}
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(const char *s, char delimiter)
{
	int		word_count;
	char	**result;

	if (!s)
		return (NULL);
	word_count = count_words(s, delimiter);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (fill_words(s, delimiter, result));
}
