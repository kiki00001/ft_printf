/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 06:35:34 by heahn             #+#    #+#             */
/*   Updated: 2021/10/18 02:19:36 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_c(char c)
{
	return (write(1, &c, sizeof(char)));
}

int	ft_type_s(char *s)
{
	if (!s)
		s = "(null)";
	return (write(1, s, ft_strlen(s) * sizeof(char)));
}

int	ft_type_p(unsigned long p, char *base)
{
	char	*str;
	char	*temp;
	int		len;

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
	int		rtn;
	char	*str;

	rtn = 0;
	str = ft_itoa(d);
	rtn += write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (rtn);
}

int	ft_type_ux(unsigned int x, char *base)
{
	int		rtn;
	char	*str;

	rtn = 0;
	str = ft_htoa(x, base);
	rtn = write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (rtn);
}
