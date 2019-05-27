/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:31:39 by nihuynh           #+#    #+#             */
/*   Updated: 2019/05/26 23:23:02 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include "engine.h"
# include "tools.h"

# include "fractol.h"

uint32_t	process_pixel(int x, int y, void *arg)
{
	(void)x;
	(void)y;
	t_int_pt2 *data;

	data = arg;
	if (data->x)
		return (0xFF0000);
	return (0x00FF00);

	// return (0x0000FF);
}

int	run(void)
{
	t_engine_handle	*engine_handle;
	t_int_pt2		data;

	data.x = 0;
	data.y = 1;
	engine_handle = init_engine(800, 400, 1, &process_pixel);
	start_engine(engine_handle, &data, 4);
	return (0);
}

int	run_fractol(void)
{
	t_engine_handle	*engine_handle;
	t_fractol		data;

	fractol_init_data(&data, 2000, 2000);
	engine_handle = init_engine(1000, 1000, 2, &fractol_pixel);
	start_engine(engine_handle, &data, 8);
	return (0);
}

int main(void)
{
	// run();
	run_fractol();
	// while ((42))
	// 	;
	// run_fractol();
	return 0;
}


