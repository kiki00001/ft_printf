/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 06:35:34 by heahn             #+#    #+#             */
/*   Updated: 2021/10/14 04:21:52 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_c(char c)
{
	write(1, &c, 1);
	return (1);
	//return (write(1, &c, sizeof(char)));
}

int ft_type_s(char *s)
{
	if (!s)
		s = "NULL";
	return (write(1, s, ft_strlen(s) * sizeof(char)));
}

int	ft_type_p(unsigned long p, char *base)
{
	char *str;
	char *temp;
	int	len;

	str = ft_htoa(p, base);
	temp = str;
	str = ft_strjoin("0x", temp);
	free(temp);
	len = write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (len);
}


int	ft_type_id(int d)
{
	char	*str;
	int		len;

	len	= 0;
	if (d < 0)
	{
		str = ft_itoa(-(long)d);
		len += write(1, "-", sizeof(char));		
	}
	else
		str = ft_itoa(d);
	len += write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (len);
}

int	ft_type_ux(unsigned int x, char *base)
{
	int rtn;
	char	*str;

	str = ft_htoa(x, base);
	rtn = write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (rtn);
}
