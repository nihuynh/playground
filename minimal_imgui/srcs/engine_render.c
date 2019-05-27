/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 20:16:51 by nihuynh           #+#    #+#             */
/*   Updated: 2019/05/27 11:57:00 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "engine_struct.h"
# include "tools.h"

# define C_MASK		0xFF000000

static inline t_int_pt2
	get_real_coordinate(t_thr_slice	*slice, int idx)
{
	t_int_pt2	res;
	int			idx_total;

	idx_total = slice->idx_thr * slice->engine->thr_limit + idx;
	res.x = idx_total % slice->engine->img.width;
	res.y = idx_total / slice->engine->img.width;
	return (res);
}

static inline void
	*process_data(void *arg)
{
	t_thr_slice	*slice;
	t_int_pt2	screen_space;
	uint32_t	idx;
	uint32_t	color;

	slice = arg;
	idx = 0;
	while (idx < slice->engine->thr_limit)
	{
		screen_space = get_real_coordinate(slice, idx);
		color = slice->engine->do_pxl(screen_space.x, screen_space.y, slice->prg_data);
		slice->pixels[idx] = color | C_MASK;
		idx++;
	}
	pthread_exit(NULL);
}

void
	engine_render(t_engine *engine)
{
	uint32_t	cthr;
	int			sats;
	void		*ptr;
	long		elapsed_time;

	cthr = -1;
	sats = 0;
	if (!engine->need_render)
		return ;
	elapsed_time = curr_usec();
	while (++cthr < engine->thread_count && !sats)
	{
		ptr = &(engine->threads[cthr]);
		sats = pthread_create(&engine->threads[cthr].thread, NULL, process_data, ptr);
	}
	cthr = -1;
	while (++cthr < engine->thread_count)
		pthread_join(engine->threads[cthr].thread, NULL);
	elapsed_time = curr_usec() - elapsed_time;
	engine->need_render = false;
	printf("Frame took %f ms to render\n", (float)elapsed_time / 1000);
}
