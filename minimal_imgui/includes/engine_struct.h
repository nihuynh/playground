/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 18:45:43 by nihuynh           #+#    #+#             */
/*   Updated: 2019/05/26 21:05:43 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_STRUCT_H
# define ENGINE_STRUCT_H

# include <stdint.h>
# include <stdbool.h>
# include <SDL.h>
# include <pthread.h>
# include "engine_handle.h"


typedef struct s_engine		t_engine;
typedef struct s_img		t_img;
typedef struct s_thr_slice	t_thr_slice;

struct				s_img
{
	int				limit;
	int				height;
	int				width;
	uint32_t		*pixels;
};

struct				s_thr_slice
{
	pthread_t		thread;
	uint32_t		*pixels;
	uint32_t		idx_thr;
	t_engine		*engine;
	void			*prg_data;
};

struct				s_engine
{
	t_engine_handle	*handle;
	uint32_t		(*do_pxl) (int, int, void*);
	void			*prg_data;
	int				vp_height;
	int				vp_width;
	t_int_pt2		render_size;
	int				render_scale;
	SDL_Window		*win;
	bool			need_render;
	t_img			img;
	uint32_t		thr_limit;
	uint32_t		thread_count;
	t_thr_slice		*threads;
};

#endif
