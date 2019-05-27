/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:21:35 by nihuynh           #+#    #+#             */
/*   Updated: 2019/05/26 21:25:05 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdint.h>
#include "engine_handle.h"

/*
** Definition for the fractol project :
** Config :
** TYPE_Z is the type of float use in the complex plane
*/

# define DEBUG		0
# define DEBUG_LEAK	0
# define MAC		DEV
# define TYPE_Z		double
# define Z_ABS(x)	fabs(x)
# define ITER_MAX	100

/*
** Keybinding :
*/

# define KEY_SYS_OUT 53

/*
** Static def :
** TYPE_C is the type for the imgstr
** C_UI is the default color for the text
*/

# define DEV			0
# define MACB			1
# define IMAC			2
# define IMAC4K			3

# define MANDEL			0
# define JULIA			1
# define BURNING		2
# define BURNING_JULIA	3
# define SYM			4
# define SYM_JULIA		5
# define TYPE_C			unsigned int

# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0

/*
** Automatic parameters :
*/

# if (MAC == MACB)
#  define WIN_TITLE		"Fractol on macbook"
#  define M_XMIN		-2.8
#  define M_XMAX		1.3
#  define J_X			2
#  define BJ_X			3
# elif (MAC == IMAC)
#  define WIN_TITLE		"Fractol @42"
#  define M_XMIN		-2.8
#  define M_XMAX		1.3
#  define J_X			2.35
#  define BJ_X			3
# elif (MAC == IMAC4K)
#  define WIN_TITLE		"Fractol @42"
#  define M_XMIN		-2.8
#  define M_XMAX		1.3
#  define J_X			2.35
#  define BJ_X			3
# else
#  define WIN_TITLE		"Fractol"
#  define M_XMIN		-2.1
#  define M_XMAX		0.6
#  define J_X			2
#  define BJ_X			2
# endif

# define B_X			2
# define B_X_OFS		0.5
# define B_Y_OFS		0.5

/*
** Structures :
*/

typedef struct		s_fractol
{
	int				type;
	TYPE_Z			x_min;
	TYPE_Z			x_max;
	TYPE_Z			step;
	TYPE_Z			y_min;
	TYPE_Z			y_max;
	int				iter_max;
	TYPE_Z			c_r;
	TYPE_Z			c_i;
	t_engine_handle	*handle;
}					t_fractol;

typedef struct		s_local_val
{
	TYPE_Z			z_r;
	TYPE_Z			z_i;
	TYPE_Z			c_r;
	TYPE_Z			c_i;
	TYPE_Z			square_r;
	TYPE_Z			square_i;
}					t_local_val;

/*
** Prototypes :
*/

void				fractol_init_data(t_fractol *data, int render_w, int render_h);
uint32_t			fractol_pixel(int x, int y, void *arg);

#endif
