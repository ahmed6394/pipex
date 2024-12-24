/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:47:08 by gahmed            #+#    #+#             */
/*   Updated: 2024/10/14 11:37:28 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*zero_handle(void)
{
	char	*str;

	str = (char *)malloc(2);
	if (!str)
		return (0);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*pos_hande(int n, char *str, int len)
{
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		is_negative;

	len = count_digits(n);
	is_negative = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		is_negative = 1;
		n = -n;
	}
	else if (n == 0)
		return (zero_handle());
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	pos_hande(n, str, len);
	if (is_negative)
		str[0] = '-';
	return (str);
}

// #include <stdio.h>

// int main()
// {
//     printf("%s\n", ft_itoa(42));              // "42"
//     printf("%s\n", ft_itoa(-623));             // "-42"
//     printf("%s\n", ft_itoa(0));               // "0"
//     printf("%s\n", ft_itoa(-2147483648));     // "-2147483648"
//     return 0;
// }