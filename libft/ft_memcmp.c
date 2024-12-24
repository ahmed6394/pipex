/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:57:38 by gahmed            #+#    #+#             */
/*   Updated: 2024/10/09 20:51:44 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n <= 0)
	{
		return (0);
	}
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (i < n)
		return (str1[i] - str2[i]);
	return (0);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
//     char s1[] = "Gi";
//     char s2[] = "gdhds";
//     int res = ft_memcmp(s1, s2, 2);
//     int res2 = memcmp(s1, s2, 2);
//     printf("%i\n", res);
//     printf("%i\n", res2);
// }