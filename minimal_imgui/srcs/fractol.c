/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:22:11 by nihuynh           #+#    #+#             */
/*   Updated: 2019/05/26 21:24:24 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdint.h>

static inline int
	iter_julbrot(t_fractol *fractol, int x, int y)
{
	t_local_val	p;
	int		iter;

	iter = -1;
	p.z_r = fractol->x_min + (TYPE_Z)x * fractol->step;
	p.z_i = fractol->y_min + (TYPE_Z)y * fractol->step;
	p.square_r = p.z_r * p.z_r;
	p.square_i = p.z_i * p.z_i;
	p.c_r = (fractol->type % 2 == MANDEL) ? p.z_r : fractol->c_r;
	p.c_i = (fractol->type % 2 == MANDEL) ? p.z_i : fractol->c_i;
	while (++iter < fractol->iter_max && (p.square_r + p.square_i) <= 4)
	{
		p.z_i = p.z_r * p.z_i;
		p.z_i += p.z_i + p.c_i;
		p.z_r = p.square_r - p.square_i + p.c_r;
		p.square_r = p.z_r * p.z_r;
		p.square_i = p.z_i * p.z_i;
	}
	return (iter);
}

static inline TYPE_C
	rgbtoi(float r, float g, float b)
{
	TYPE_C	res;

	res = (int)(r * 255) << 16;
	res += (int)(g * 255) << 8;
	res += (int)(b * 255);
	return (res);
}

static inline TYPE_C
	bernstein(int type_palette, float t)
{
	float r;
	float g;
	float b;

	r = 9 * (1 - t) * t * t * t;
	g = 15 * (1 - t) * (1 - t) * t * t;
	b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t;
	if (type_palette == 1)
		return (rgbtoi(r, b, g));
	else if (type_palette == 2)
		return (rgbtoi(b, g, r));
	else if (type_palette == 3)
		return (rgbtoi(b, r, g));
	else if (type_palette == 4)
		return (rgbtoi(g, b, r));
	else if (type_palette == 5)
		return (rgbtoi(g, r, b));
	return (rgbtoi(r, g, b));
}

void
	fractol_init_data(t_fractol *data, int render_w, int render_h)
{
	data->type = MANDEL;
	data->x_min = M_XMIN;
	data->x_max = M_XMAX;
	data->step = (data->x_max - data->x_min) / (render_w - 1);
	data->y_min = -data->step * (render_h - 1) / 2;
	data->y_max = data->step * (render_h - 1) / 2;
	data->iter_max = ITER_MAX;
}

uint32_t
	fractol_pixel(int x, int y, void *arg)
{
	uint32_t	res;
	int			iter;
	t_fractol	*data;

	data = arg;
	iter = iter_julbrot(data, x, y);
	res = bernstein(1, (float) iter / data->iter_max);
	return (res);
}
