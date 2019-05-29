#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../../LibftHub/libft.h"

typedef struct		s_arg
{
	char	flag_hash;
	char	flag_zero;
	char	flag_minus;
	char	flag_space;
	char	flag_plus;
	ssize_t	width;
	ssize_t	prec;
	char	len_mod[3];
	char	conv;
}					t_arg;

typedef struct		s_conv
{
	char	conv;
	void	(*f)(char **format_ptr, t_arg arg, va_list *ap);
}					t_conv;

/*
** Print functions
*/
void			ft_printarg_c(char **format_ptr, t_arg arg, va_list *ap);
void			ft_printarg_s(char **format_ptr, t_arg arg, va_list *ap);
void			ft_printarg_p(char **format_ptr, t_arg arg, va_list *ap);
void			ft_printarg_d(char **format_ptr, t_arg arg, va_list *ap);
void			ft_printarg_i(char **format_ptr, t_arg arg, va_list *ap);
void			ft_printarg_o(char **format_ptr, t_arg arg, va_list *ap);
void			ft_printarg_u(char **format_ptr, t_arg arg, va_list *ap);
void			ft_printarg_x(char **format_ptr, t_arg arg, va_list *ap);
void			ft_printarg_big_x(char **format_ptr, t_arg arg, va_list *ap);
void			ft_printarg_f(char **format_ptr, t_arg arg, va_list *ap);
void			ft_printarg_pcnt(char **format_ptr, t_arg arg, va_list *ap);
/*
** Get Argument
*/
int				arg_flag(char **f, t_arg *arg);
int				arg_width(char **f, t_arg *arg);
int				arg_prec(char **f, t_arg *arg);
int				arg_len_mod(char **f, t_arg* arg);
char			arg_conv(char **f, t_arg *arg);
/*
** Aux functions
*/
void        	ft_llputnbr(long long nb);
int		    	nb_len(long long nb);
int         	unsigned_nb_len(unsigned long long nb);
void			reset_arg(t_arg *arg);
/*
** Aux print functions
*/
void			prt_width(int sign, int len, t_arg arg);
void    		prt_prec(ssize_t n);
void			prt_sign(long long nb, t_arg arg);
void			prt_decimal(long double nb, ssize_t prec);


#endif
