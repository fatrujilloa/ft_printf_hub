/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:22:11 by ftrujill          #+#    #+#             */
/*   Updated: 2019/05/29 18:43:00 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../LibftHub/libft.h"
#include "printf.h"
#include "conversions.h"

int			conv_pos(char c)
{
	int i;

	i = 0;
	while (c != g_conv_tab[i].conv)
		i++;
	return (i);
}

int		get_arg(char **format_ptr, t_arg *arg)
{
	if (!(**format_ptr))
		return (0);
	if (!(arg_flag(format_ptr, arg))
		|| !(arg_width(format_ptr, arg))
		|| !(arg_prec(format_ptr, arg))
		|| !(arg_len_mod(format_ptr, arg))
		|| !(arg_conv(format_ptr, arg)))
		return (0);
	(*format_ptr)++;
	return (1);
}

int		nb_arg(const char *restrict format, ...)
{
	int i;

	i = 0;
	while (*format)
		if (*format++ == '%')
			i++;
	return (i);
}

int		print_result(char *str, t_arg *arg, va_list *ap)
{
	int		i;
	int		j;
	void	(*f)(char **f, t_arg arg, va_list *ap);

	i = 0;
	j = 0;
	while (str[j])
	{
		while (str[j] && str[j] != '%')
			write(1, &str[j++], 1);
		if (!(str[j++]))
			break ;
		f = g_conv_tab[conv_pos(arg[i].conv)].f;
		f(&str, arg[i++], ap);
	}
	free(str);
	free(arg);
	return (1);
}

int		ft_printf(const char *restrict format, ...)
{
	int		i;
	int		j;
	va_list	ap;
	t_arg	*arg;
	char	*copy;

	i = 0;
	j = 0;
	if (!(copy = (char*)malloc(ft_strlen(format) + 1)) ||
		!(arg = (t_arg*)malloc((nb_arg(format)) * sizeof(t_arg))))
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		reset_arg(&arg[i]);
		while (*format && *format != '%')
			copy[j++] = *format++;
		copy[j++] = *format;
		if (!(*format) || !*(++format))//Should be error if there is nothing after %?
			break ;
		//write (1, "c", 1);
		if (!(get_arg(&format, &arg[i++])))
			return (-1);
	}
	copy[j] = 0;
	//check there is no more arguments.
	return (print_result(copy, arg, &ap) ? 0 : -1);
}
