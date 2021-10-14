/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:39:29 by heahn             #+#    #+#             */
/*   Updated: 2021/10/14 22:21:47 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(va_list ap, char type)
{
	if (type == 'c')
		return (ft_type_c(va_arg(ap, int)));
	else if (type == 's')
		return (ft_type_s(va_arg(ap, char *)));
	else if (type == 'p')
		return (ft_type_p(va_arg(ap, unsigned long), "0123456789abcdef"));
	else if (type == 'd' || type == 'i')
		return (ft_type_id(va_arg(ap, int)));
	else if (type == 'u')
		return (ft_type_ux(va_arg(ap, unsigned int), "0123456789"));
	else if (type == 'x')
		return (ft_type_ux(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (type == 'X')
		return (ft_type_ux(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (type == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

int	ft_format(va_list ap, char *format)
{
	int	rtn;

	rtn = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			rtn += ft_type(ap, *format);
		}
		else
			rtn += write(1, format, 1);
		format++;
	}
	return (rtn);
}

int	ft_printf(const char *format, ...)
{
	int		rtn;
	va_list	ap;

	va_start(ap, format);
	rtn = ft_format(ap, (char *)format);
	va_end(ap);
	return (rtn);
}
