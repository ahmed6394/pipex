/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:44:33 by gahmed            #+#    #+#             */
/*   Updated: 2024/10/10 12:00:15 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = 0;
	while (src[slen])
		slen++;
	if (dstsize < 1)
		return (slen);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char dst[20];
//     char src[] = "This is";
//     int n = 0;
//     int res = strlcpy(dst, src, n);
//     int res1 = ft_strlcpy(dst, src, n);
//     printf("res in lib %i\n", res);
//     printf("res in fn %i\n", res1);
// }