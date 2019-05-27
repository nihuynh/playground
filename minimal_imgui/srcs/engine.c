/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 19:51:56 by nihuynh           #+#    #+#             */
/*   Updated: 2019/05/26 23:21:01 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "engine.h"
# include "engine_loop.h"
# include <SDL.h>

t_engine
	*get_engine(t_engine *engine_ptr)
{
	static t_engine *save_engine_ptr;

	if (engine_ptr != NULL)
		save_engine_ptr = engine_ptr;
	return (save_engine_ptr);
}


void	realloc_pxl(t_engine *engine, int width, int height)
{
	uint32_t	idx;
	int			ofs;

	if (engine->img.pixels)
		free(engine->img.pixels);
	engine->img.height = height;
	engine->img.width = width;
	engine->img.limit = width * height;
	engine->thr_limit = (width * height) / engine->thread_count;
	if (!(engine->img.pixels = malloc(sizeof(uint32_t) * width * height)))
		exit(EXIT_FAILURE);
	idx = 0;
	while (idx < engine->thread_count)
	{
		ofs = idx * engine->thr_limit;
		engine->threads[idx].pixels = &engine->img.pixels[ofs];
		idx++;
	}
}

t_engine_handle
	*init_engine(int width, int height, float render_scale, uint32_t (*do_pxl) (int, int, void*))
{
	t_engine	*engine_data;

	if (!(engine_data = malloc(sizeof(t_engine))))
		exit(EXIT_FAILURE);
	bzero(engine_data, sizeof(t_engine));
	if (!(engine_data->handle = malloc(sizeof(t_engine_handle))))
		exit(EXIT_FAILURE);
	bzero(engine_data->handle, sizeof(t_engine_handle));
	render_scale = (render_scale <= 0 ) ? 1 : render_scale;
	engine_data->do_pxl = do_pxl;
	engine_data->handle->do_pxl = do_pxl;
	engine_data->handle->viewport.x = width;
	engine_data->handle->viewport.y = height;
	engine_data->handle->img = engine_data->img.pixels;
	engine_data->handle->engine = engine_data;
	engine_data->handle->need_render = true;
	engine_data->vp_height = height;
	engine_data->vp_width = width;
	engine_data->render_scale = (int) (render_scale * 100);
	engine_data->render_size.x = width;
	engine_data->render_size.y = height;
	engine_data->img.height = height * render_scale;
	engine_data->img.width = width * render_scale;
	engine_data->img.limit = engine_data->img.width * engine_data->img.height;
	if (!(engine_data->img.pixels = malloc(sizeof(uint32_t) * engine_data->img.limit)))
		exit(EXIT_FAILURE);
	bzero(engine_data->img.pixels, sizeof(uint32_t) * engine_data->img.limit);
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		exit(EXIT_FAILURE);
	if (!(engine_data->win = SDL_CreateWindow("RT",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN)))
		exit(EXIT_FAILURE);
	SDL_SetHint(SDL_HINT_BMP_SAVE_LEGACY_FORMAT, "1");
	get_engine(engine_data);
	return (engine_data->handle);
}

inline static t_thr_slice
	init_thr_slice(t_engine *engine, void *data, uint32_t idx_thr)
{
	t_thr_slice	slice;

	slice.idx_thr = idx_thr;
	slice.engine = engine;
	slice.prg_data = data;
	slice.pixels = &engine->img.pixels[idx_thr * engine->thr_limit];
	return (slice);
}

int
	start_engine(t_engine_handle *engine_handle, void *prg_data, uint32_t thr_count)
{
	uint32_t	idx;
	t_engine	*engine;

	engine = engine_handle->engine;
	engine_handle->prg_data = prg_data;
	engine->prg_data = prg_data;
	if (thr_count == 0)
	{
		printf("The thread count cannot be null\n");
		exit(EXIT_FAILURE);
	}
	engine->thread_count = thr_count;
	engine->thr_limit = engine->img.limit / thr_count;
	if (engine->img.limit % thr_count != 0)
	{
		printf("The thread count is invalid\nthr_count = %d engine->img.limit %% thr_count = %d", thr_count, engine->img.limit % thr_count);
		exit(EXIT_FAILURE);
	}
	if (!(engine->threads = malloc(sizeof(t_thr_slice) * thr_count)))
		exit(EXIT_FAILURE);
	bzero(engine->threads, sizeof(t_thr_slice) * thr_count);
	idx = 0;
	while (idx < thr_count)
	{
		engine->threads[idx] = init_thr_slice(engine, prg_data, idx);
		idx++;
	}
	engine->need_render = true;
	engine_loop(engine);
	return (EXIT_SUCCESS);
}
