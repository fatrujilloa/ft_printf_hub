/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:05:14 by ftrujill          #+#    #+#             */
/*   Updated: 2019/05/29 18:55:59 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../LibftHub/libft.h"
#include "printf.h"

void	prt_width(int sign, int len, t_arg arg)
{
	ssize_t	n;
	char	c;

	if (arg.width > ft_max(arg.prec, len))
	{
		c = arg.flag_zero && !(arg.flag_minus) ? '0' : ' ';
		n = arg.width - ft_max(arg.prec + sign, len);
		while (n > 0)
		{
			write(1, &c, 1);
			n--;
		}
	}
}

void	prt_prec(ssize_t n)
{
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
}

void	prt_sign(long long nb, t_arg arg)
{
	nb < 0 ? write(1, "-", 1) : 0;
	nb >= 0 && arg.flag_space && !(arg.flag_plus) ? write(1, " ", 1) : 0;
	nb >= 0 && arg.flag_plus ? write(1, "+", 1) : 0;
}

void	prt_decimal(long double nb, ssize_t prec)
{
	write(1, ".", 1);
	nb = 10 * (nb - (long long)nb);
    while (prec > 0)
    {
        ft_putnbr((int)nb);
        nb = 10 * (nb - (long long)nb);
        prec--;
    }
}