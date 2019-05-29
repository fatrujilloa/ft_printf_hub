/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:00:55 by ftrujill          #+#    #+#             */
/*   Updated: 2019/05/29 17:28:34 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../LibftHub/libft.h"
#include "printf.h"

int		arg_flag(char **f, t_arg *arg)
{
	char	c;

	if (!(c = **f))
		return (0);
	while (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
	{
		if (c == '#')
			arg->flag_hash = c;
		else if (c == '0')
			arg->flag_zero = c;
		else if (c == '-')
			arg->flag_minus = c;
		else if (c == ' ')
			arg->flag_space = c;
		else if (c == '+')
			arg->flag_plus = c;
		if (!(c = *(++(*f))))
			return (0);
	}
	return (1);
}

int		arg_width(char **f, t_arg *arg)
{
	ssize_t	width;

	if (!(**f))
		return (-1);
	width = 0;
	while (ft_isdigit(**f))
	{
		width = 10 * width + **f - 48;
		(*f)++;
	}
	arg->width = width;
	return (**f ? 1 : 0);
}

int		arg_prec(char **f, t_arg *arg)
{
	ssize_t prec;

	if (!(**f))
		return (0);
	if (**f != '.')
	{
		arg->prec = -1;
		return (1);
	}
	(*f)++;
	prec = 0;
	arg->flag_zero = 0;
	while (ft_isdigit(**f))
	{
		prec = 10 * prec + **f - 48;
		(*f)++;
	}
	arg->prec = prec;
	return (**f ? 1 : 0);
}

int		arg_len_mod(char **f, t_arg *arg)
{
	if (!(**f))
		return (0);
	if (**f == 'h')
	{
		arg->len_mod[0] = 'h';
		if (*(++(*f)) == 'h')
			arg->len_mod[1] = *((*f)++);
	}
	else if (**f == 'l')
	{
		arg->len_mod[0] = 'l';
		if (*(++(*f)) == 'l')
		{
			arg->len_mod[1] = 'l';
			(*f)++;
		}
	}
	else if (**f == 'L')
		arg->len_mod[0] = 'L';
	return (1);
}

char	arg_conv(char **f, t_arg *arg)
{
	char	c;

	c = **f;
	if (c != 'c' && c != 's' && c != 'p' && c != 'd' && c != 'i' &&
		c != 'o' && c != 'u' && c != 'x' && c != 'X' && c != 'f' &&
		c != '%')
		return (0);
	arg->conv = c;
	if (arg->prec == -1)
		arg->prec = (c == 'f') ? 6 : 0;
	return (1);
}
