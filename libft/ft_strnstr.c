/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:05:34 by gahmed            #+#    #+#             */
/*   Updated: 2024/10/10 13:53:48 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (i + ft_strlen(needle) > len)
			return (0);
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
//     char buffer1[] = "computer pro program";
//     char ch[] = "pro";
//     char *ptr2 = ft_strnstr(buffer1, ch,20);
//     char *ptr = strnstr(buffer1, ch, 20);
//     printf("The first occurrence of '%s' 
// in '%s' is '%s'\n", ch, buffer1, ptr);
//     printf("The first occurrence of '%s' in
//  '%s' is '%s'\n", ch, buffer1, ptr2);
//     return 0;
// }