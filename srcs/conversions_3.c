/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:43:13 by ftrujill          #+#    #+#             */
/*   Updated: 2019/05/29 18:55:54 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../LibftHub/libft.h"
#include "printf.h"

void	ft_printarg_f(char **format_ptr, t_arg arg, va_list *ap)
{
    long double		nb;
	int				len;
	int				sign;

	nb = va_arg(*ap, double);
	if (*arg.len_mod == 'L')
		nb = (long double)nb;
	len = nb >= 0 && (arg.flag_space || arg.flag_plus) ?
		nb_len((long long)nb) + 1 : nb_len((long long)nb);
	len = arg.prec != 0 ? len + 1 + arg.prec : len;
	sign = (nb < 0 || arg.flag_space || arg.flag_plus) ? 1 : 0;
	arg.flag_minus ? 0 : prt_width(sign, len, arg);
	prt_sign(nb, arg);
	ft_llputnbr((long long)nb);
	arg.prec != 0? prt_decimal(nb, arg.prec) : 0;
	arg.flag_minus ? prt_width(sign, len, arg) : 0;
}
