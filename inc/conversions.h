#ifndef CONVERSIONS_H
# define CONVERSIONS_H

t_conv              g_conv_tab[] =
    {
        {'c', &ft_printarg_c},
        {'s', &ft_printarg_s},
        {'p', &ft_printarg_p},
        {'d', &ft_printarg_d},
        {'i', &ft_printarg_i},
        {'o', &ft_printarg_o},
        {'u', &ft_printarg_u},
        {'x', &ft_printarg_x},
        {'X', &ft_printarg_big_x},
        {'f', &ft_printarg_f},
		{'%', &ft_printarg_pcnt}
    };

#endif
