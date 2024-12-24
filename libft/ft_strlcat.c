/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:28:56 by gahmed            #+#    #+#             */
/*   Updated: 2024/10/10 13:04:12 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;

	slen = ft_strlen(src);
	dlen = 0;
	while (dlen < dstsize && dst[dlen] != '\0')
		dlen++;
	if (dlen == dstsize)
		return (slen + dstsize);
	i = 0;
	while (src[i] != '\0' && (dlen + i + 1) < dstsize)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	if ((dlen + i) < dstsize)
		dst[dlen + i] = '\0';
	else if (dstsize > 0)
		dst[dstsize - 1] = '\0';
	return (dlen + slen);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char dst[20];
//     char src[] = "this is";
//     int n = sizeof(dst);
//     int result = ft_strlcat(dst, src, n);
// 		int expected_length = strlcat(dst, src, n); 
// Expected length of "Hello, World!"
// printf("Result: %s\n", dst);
// printf("Expected: %s\n", expected_dst);
//     printf("Returned Length: %i\n", result);
//     printf("Expected Length: %i\n", expected_length);
// }