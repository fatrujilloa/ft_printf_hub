/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:43:13 by ftrujill          #+#    #+#             */
/*   Updated: 2019/06/01 22:02:39 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

long double	rounding(long double nb, ssize_t prec)
{
	long double n;
	long double r;

	n = nb >= 0 ? nb - (long long)nb : -(nb - (long long)nb);
	r = 1.0;
	while (prec > 0)
	{
		n = 10 * n;
		r = r / 10;
		n = n - (long long)n;
		prec--;
	}
	if (n > 0.5)
		nb = nb >= 0 ? nb + r : nb - r;
	return (nb);
}

void		prt_decimal(long double nb, ssize_t prec)
{
	write(1, ".", 1);
	nb = nb > 0 ? 10 * (nb - (long long)nb) : -10 * (nb - (long long)nb);
	while (prec > 0)
	{
		ft_putnbr((int)nb);
		nb = 10 * (nb - (long long)nb);
		prec--;
	}
}

int			ft_printarg_f(t_arg arg, va_list *ap)
{
	long double		nb;
	int				len;
	int				sign;

	nb = *arg.len_mod == 'L' ? va_arg(*ap, long double) : va_arg(*ap, double);
	len = nb >= 0 && (arg.flag_space || arg.flag_plus) ?
		nb_len((long long)nb) + 1 : nb_len((long long)nb);
	len = (arg.prec != 0 || arg.flag_hash) ? len + 1 + arg.prec : len;
	sign = (nb < 0 || arg.flag_space || arg.flag_plus) ? 1 : 0;
	arg.flag_minus ? 0 : prt_width(sign, len, arg);
	prt_sign(nb, arg);
	nb = rounding(nb, arg.prec);
	ft_llputnbr((long long)nb);
	(arg.flag_hash || arg.prec) ? prt_decimal(nb, arg.prec) : 0;
	arg.flag_minus ? prt_width(sign, len, arg) : 0;
	return (ft_max(arg.width, ft_max(arg.prec, len) + sign));
}
