/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 20:19:51 by nihuynh           #+#    #+#             */
/*   Updated: 2019/05/26 22:46:11 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "engine_struct.h"
# include "engine_render.h"
# include "engine_free.h"
# include "engine_ui.h"
# include "fractol.h"
# define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
# define GL_SILENCE_DEPRECATION
#include "cimgui.h"

void	engine_loop(t_engine *engine)
{
	SDL_Event	event;
	t_fractol	*data;
	t_truc		ui_context;
	int			quit = 0;

	data = engine->handle->prg_data;
	ui_context = engine_hook_render(engine->win, &engine->img);
	while (!quit && engine->handle != NULL)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				quit = 1;
		}
		engine_render(engine);
		engine_update_render(&ui_context);
		engine_ui(&ui_context);
		fractol_init_data(data, engine->img.width, engine->img.height);
	}
	engine_free_context(&ui_context);
	engine_free(engine);
}
