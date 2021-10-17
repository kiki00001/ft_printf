/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:40:24 by heahn             #+#    #+#             */
/*   Updated: 2021/10/18 02:17:26 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_type(va_list ap, char type);
int		ft_format(va_list ap, char *format);
int		ft_printf(const char *format, ...);
int		ft_type_c(char c);
int		ft_type_s(char *s);
int		ft_type_p(unsigned long p, char *base);
int		ft_type_id(int d);
int		ft_type_ux(unsigned int x, char *base);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
size_t	ft_len(int n);
char	*ft_itoa(int n);
char	*ft_htoa(size_t n, char *base);

#endif
