/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:41:19 by gahmed            #+#    #+#             */
/*   Updated: 2024/10/10 11:47:19 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char )c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char )c)
		return ((char *)(s + i));
	return (0);
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
//     char buffer1[] = "computer program";
//     int    ch = 'p';
//     char *ptr2 = ft_strchr(buffer1, ch);
//     char *ptr = strchr(buffer1, ch);
//     printf("The first occurrence of 
		// '%c' in '%s' is '%s'\n", ch, buffer1, ptr);
//     printf("The first occurrence 
		// of '%c' in '%s' is '%s'\n", ch, buffer1, ptr2);
//     return 0;
// }