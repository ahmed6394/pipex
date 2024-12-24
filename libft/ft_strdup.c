/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:36:12 by gahmed            #+#    #+#             */
/*   Updated: 2024/10/10 14:06:05 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dst;

	i = 0;
	while (s1[i])
	{
		i++;
	}
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (0);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char source[] = "GeeksForGeeks";
//     char* target = strdup(source); 
//     char* target2 = ft_strdup(source);  
//     printf("res from lib: %s\n", target);
//     printf("res from ft: %s\n", target2);
//     return 0;
// }