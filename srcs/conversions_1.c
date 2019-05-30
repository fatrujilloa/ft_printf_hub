/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:11:26 by ftrujill          #+#    #+#             */
/*   Updated: 2019/05/30 21:41:06 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../LibftHub/libft.h"
#include "printf.h"

void	ft_printarg_pcnt(char **format_ptr, t_arg arg, va_list *ap)
{
	write(1, "%", 1);
}

void	ft_printarg_c(char **format_ptr, t_arg arg, va_list *ap)
{
	char c;

	c = (char)va_arg(*ap, int);
	arg.flag_minus ? 0 : prt_width(0, 1, arg);
	write(1, &c, 1);
	arg.flag_minus ? prt_width(0, 1, arg) : 0;
}

void	ft_printarg_s(char **format_ptr, t_arg arg, va_list *ap)
{
	char 	*str;
	size_t	len;

	str = va_arg(*ap, char*);
	len = ft_min(ft_strlen(str), arg.prec);
	arg.flag_minus ? 0 : prt_width(0, len, arg);
	ft_putnstr(str, len);
	arg.flag_minus ? prt_width(0, len, arg) : 0;
}

void	ft_printarg_p(char **format_ptr, t_arg arg, va_list *ap)
{
	unsigned long long	nb;
	int					len;
	char				*str;
	int					sign;

	nb = va_arg(*ap, unsigned long);
	str = ft_strlower(ft_itoa_base(nb, 16));
	len = ft_strlen(str);
	sign = 2;
	arg.flag_minus ? 0 : prt_width(sign, len, arg);
	if (sign)
		write(1, "0x", 2);
	arg.prec > len ? prt_prec(arg.prec - len) : 0;
	ft_putstr(str);
	free(str);
	arg.flag_minus ? prt_width(sign, len, arg) : 0;
}

void	ft_printarg_d(char **format_ptr, t_arg arg, va_list *ap)
{
	long long		nb;
	int				len;
	int				sign;

	nb = va_arg(*ap, long long);
	if (!(*arg.len_mod))
		nb = (int)nb;
	else if (*arg.len_mod == 'h')
		nb = arg.len_mod[1] == 'h' ? (signed char)nb : (short)nb;
	else if (*arg.len_mod == 'l')
		nb = arg.len_mod[1] == 'l' ? nb : (long)nb;
	len = nb >= 0 && (arg.flag_space || arg.flag_plus) ?
		nb_len(nb) + 1 : nb_len(nb);
	sign = (nb < 0 || arg.flag_space || arg.flag_plus) ? 1 : 0;
	arg.flag_minus ? 0 : prt_width(sign, len, arg);
	prt_sign(nb, arg);
	arg.prec + sign > len ? prt_prec(arg.prec + sign - len) : 0;
	ft_llputnbr(nb);
	arg.flag_minus ? prt_width(sign, len, arg) : 0;
}
