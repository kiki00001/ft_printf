/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:39:29 by heahn             #+#    #+#             */
/*   Updated: 2021/10/14 05:36:50 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(va_list ap, char type)
{
	if (type == 'c')
		return(ft_type_c(va_arg(ap, int)));
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
	int rtn;
//	int i;

	rtn = 0;
//	i = 0;
	//while (format[i])
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			rtn += ft_type(ap, *format);
			//i++;
			//rtn += ft_type(ap, format[i]);
		}
		else
		{
			rtn += write(1, format, 1);	
		}//rtn += write(1, &format[i], 1);
		format++;
		//i++;
	}
	return (rtn);
}


int	ft_printf(const char *format, ...)
{
	int rtn;
	va_list	ap;

	va_start(ap, format);
	rtn = ft_format(ap, (char *)format);
	va_end(ap);
	return (rtn);
}

int main(void)
{
	int d;
//	char c='c';
//	string t ="string";

	d = ft_printf("%d %d %d",42, 40, 41);

	return (0);
}
