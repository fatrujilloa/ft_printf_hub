/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:43:13 by ftrujill          #+#    #+#             */
/*   Updated: 2019/05/31 10:58:01 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int		ft_printarg_f(t_arg arg, va_list *ap)
{
    long double		nb;
	int				len;
	int				sign;
	int				point;

	nb = va_arg(*ap, double);
	if (*arg.len_mod == 'L')
		nb = (long double)nb;
	len = nb >= 0 && (arg.flag_space || arg.flag_plus) ?
		nb_len((long long)nb) + 1 : nb_len((long long)nb);
	len = (arg.prec != 0 || arg.flag_hash) ? len + 1 + arg.prec : len;
	sign = (nb < 0 || arg.flag_space || arg.flag_plus) ? 1 : 0;
	arg.flag_minus ? 0 : prt_width(sign, len, arg);
	prt_sign(nb, arg);
	ft_llputnbr((long long)nb);
	point = (!arg.prec && arg.flag_hash) || arg.prec ? 1 : 0;
	(!arg.prec && arg.flag_hash) ? write(1, ".", 1) : 0;
	arg.prec ? prt_decimal(nb, arg.prec) : 0;
	arg.flag_minus ? prt_width(sign, len, arg) : 0;
	return (ft_max(arg.width, ft_max(arg.prec, len) + sign + point));
}
