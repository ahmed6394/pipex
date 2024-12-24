/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:46:00 by gahmed            #+#    #+#             */
/*   Updated: 2024/10/10 13:32:21 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			return ((void *)(ptr + i));
		}
		i++;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
//     char buffer1[] = "computer program";
//     int    ch = 'p';
//     char *ptr2 = ft_memchr(buffer1, ch, 4);
//     char *ptr = memchr(buffer1, ch, 4);
//     printf("The first occurrence of '%c' 
			// in '%s' is '%s'\n", ch, buffer1, ptr);
//     printf("The first occurrence 
			// of '%c' in '%s' is '%s'\n", ch, buffer1, ptr2);
//     return 0;
// }