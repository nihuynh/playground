/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 02:35:14 by nihuynh           #+#    #+#             */
/*   Updated: 2019/01/03 02:36:15 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_H
# define FT_CONV_H

#include <stdarg.h>
#include "ft_printf.h"


int			f_unkn(va_list vl, t_data *data);
int			form_percent(va_list vl, t_data *data);
int			form_integer(va_list vl, t_data *data);
int			form_unsigned(va_list vl, t_data *data);
int			form_octal(va_list vl, t_data *data);
int			form_hexa(va_list vl, t_data *data);
int			form_float(va_list vl, t_data *data);
int			form_character(va_list vl, t_data *data);
int			form_string(va_list vl, t_data *data);
int			form_pointer(va_list vl, t_data *data);

typedef int (*conv_table)(va_list vl, t_data *data);

conv_table g_dispach[128] =
{
	&f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn,
	&f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn,
	&f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn,
	&f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn,
	&f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &form_percent, &f_unkn, &f_unkn,
	&f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn,
	&f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn,
	&f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn,
	&f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn,
	&f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn,
	&f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn,
	&form_hexa, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn,
	&f_unkn, &f_unkn, &f_unkn, &form_character, &form_integer, &f_unkn, &form_float, &f_unkn,
	&f_unkn, &form_integer, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &form_octal,
	&form_pointer, &f_unkn, &f_unkn, &form_string, &f_unkn, &form_unsigned, &f_unkn, &f_unkn,
	&form_hexa, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn, &f_unkn
};

#endif