/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 07:33:09 by heahn             #+#    #+#             */
/*   Updated: 2021/10/18 02:01:48 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_len(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < len)
		len += 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	str[len] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i += 1;
	}
	while (i < len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_htoa(size_t n, char *base)
{
	int		len;
	char	*str;
	size_t	i;

	len = 0;
	i = n;
	if (n == 0)
		len = 1;
	while (i != 0)
	{
		i /= ft_strlen(base);
		len++;
	}
	str = (char *)malloc((len + 1) * sizeof(*base));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = base[n % (size_t)ft_strlen(base)];
		n /= (size_t)ft_strlen(base);
	}
	return (str);
}
