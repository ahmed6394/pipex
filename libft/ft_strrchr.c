/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:05:15 by gahmed            #+#    #+#             */
/*   Updated: 2024/10/10 13:17:11 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	i = len;
	while (i > 0)
	{
		if (s[i - 1] == (char )c)
			return ((char *)(s + i - 1));
		i--;
	}
	if (s[len] == (char)c)
		return ((char *)(s + len));
	return (0);
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
//     char buffer1[] = "computer program";
//     int    ch = 'r';
//     char *ptr2 = ft_strrchr(buffer1, ch);
//     char *ptr = strrchr(buffer1, ch);
//     printf("The first occurrence in lib of 
// '%c' in '%s' is '%s'\n", ch, buffer1, ptr);
//     printf("The first occurrence in fn 
// of '%c' in '%s' is '%s'\n", ch, buffer1, ptr2);
//     return 0;
// }