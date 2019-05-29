/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:13:18 by ftrujill          #+#    #+#             */
/*   Updated: 2019/05/29 15:14:30 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../LibftHub/libft.h"
#include "printf.h"

void	ft_printarg_i(char **format_ptr, t_arg arg, va_list *ap)
{
	ft_printarg_d(format_ptr, arg, ap);
}

void	ft_printarg_o(char **format_ptr, t_arg arg, va_list *ap)
{
	unsigned long long	nb;
	int					len;
	char				*str;
	int					sign;

	nb = va_arg(*ap, unsigned long long);
	if (!(*arg.len_mod))
		nb = (unsigned int)nb;
	else if (*arg.len_mod == 'h')
		nb = arg.len_mod[1] == 'h' ? (unsigned char)nb : (unsigned short)nb;
	else if (*arg.len_mod == 'l')
		nb = arg.len_mod[1] == 'l' ? nb : (unsigned long)nb;
	str = ft_itoa_base(nb, 8);
	len = ft_strlen(str);
	sign = arg.flag_hash ? 1 : 0;
	arg.flag_minus ? 0 : prt_width(sign, len, arg);
	if (sign)
		write(1, "0", 1);
	arg.prec > len ? prt_prec(arg.prec - len) : 0;
	ft_putstr(str);
	arg.flag_minus ? prt_width(sign, len, arg) : 0;
}

void	ft_printarg_u(char **format_ptr, t_arg arg, va_list *ap)
{
	unsigned long long			nb;
	int							len;
	char						*str;

	nb = va_arg(*ap, unsigned long long);
	if (!(*arg.len_mod))
		nb = (unsigned int)nb;
	else if (*arg.len_mod == 'h')
		nb = arg.len_mod[1] == 'h' ? (unsigned char)nb : (unsigned short)nb;
	else if (*arg.len_mod == 'l')
		nb = arg.len_mod[1] == 'l' ? nb : (unsigned long)nb;
	str = ft_itoa_base(nb, 10);
	len = ft_strlen(str);
	arg.flag_minus ? 0 : prt_width(0, len, arg);
	arg.prec > len ? prt_prec(arg.prec - len) : 0;
	ft_putstr(str);
	arg.flag_minus ? prt_width(0, len, arg) : 0;
}

void	ft_printarg_x(char **format_ptr, t_arg arg, va_list *ap)
{
	unsigned long long	nb;
	int					len;
	char				*str;
	int					sign;

	nb = va_arg(*ap, unsigned long long);
	if (!(*arg.len_mod))
		nb = (unsigned int)nb;
	else if (*arg.len_mod == 'h')
		nb = arg.len_mod[1] == 'h' ? (unsigned char)nb : (unsigned short)nb;
	else if (*arg.len_mod == 'l')
		nb = arg.len_mod[1] == 'l' ? nb : (unsigned long)nb;
	str = ft_strlower(ft_itoa_base(nb, 16));
	len = ft_strlen(str);
	sign = arg.flag_hash ? 2 : 0;
	arg.flag_minus ? 0 : prt_width(sign, len, arg);
	if (sign)
		write(1, "0x", 2);
	arg.prec > len ? prt_prec(arg.prec - len) : 0;
	ft_putstr(str);
	arg.flag_minus ? prt_width(sign, len, arg) : 0;
}

void	ft_printarg_big_x(char **format_ptr, t_arg arg, va_list *ap)
{
	unsigned long long	nb;
	int					len;
	char				*str;
	int					sign;

	nb = va_arg(*ap, unsigned long long);
	if (!(*arg.len_mod))
		nb = (unsigned int)nb;
	else if (*arg.len_mod == 'h')
		nb = arg.len_mod[1] == 'h' ? (unsigned char)nb : (unsigned short)nb;
	else if (*arg.len_mod == 'l')
		nb = arg.len_mod[1] == 'l' ? nb : (unsigned long)nb;
	str = ft_itoa_base(nb, 16);
	len = ft_strlen(str);
	sign = arg.flag_hash ? 2 : 0;
	arg.flag_minus ? 0 : prt_width(sign, len, arg);
	if (sign)
		write(1, "0X", 2);
	arg.prec > len ? prt_prec(arg.prec - len) : 0;
	ft_putstr(str);
	arg.flag_minus ? prt_width(sign, len, arg) : 0;
}
