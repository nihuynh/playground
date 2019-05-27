/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_handle.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 19:57:56 by nihuynh           #+#    #+#             */
/*   Updated: 2019/05/26 21:59:00 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_HANDLE_H
# define ENGINE_HANDLE_H

# include <stdbool.h>

typedef struct s_engine_handle		t_engine_handle;

typedef	struct	s_int_pt2
{
	int			x;
	int			y;
}             	t_int_pt2;

struct				s_engine_handle
{
	void			*prg_data;
	uint32_t		(*do_pxl) (int, int, void*);
	t_int_pt2		viewport;
	uint32_t		*img;
	void			*engine;
	bool			need_render;
};

t_engine_handle		*init_engine(int width, int height, float render_scale, uint32_t (*do_pxl) (int, int, void*));
int					start_engine(t_engine_handle *engine_handle, void *prg_data, uint32_t thr_count);

#endif
