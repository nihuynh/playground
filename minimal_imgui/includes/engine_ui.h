/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_ui.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 22:31:29 by nihuynh           #+#    #+#             */
/*   Updated: 2019/05/26 19:50:10 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_UI_H
# define ENGINE_UI_H

# define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
# define GL_SILENCE_DEPRECATION

# include <SDL.h>
#include "cimgui.h"
# include "engine_struct.h"

typedef struct		s_truc
{
	uint32_t		texture_id;
	SDL_GLContext	local_context;
	ImGuiContext	*imgui_context;
	SDL_Window		*window;
	t_img			*img_ref;
}					t_truc;


t_truc	engine_hook_render(SDL_Window *window, t_img *img_ref);
void	engine_update_render(t_truc *ui_context);
void	engine_ui(t_truc *ui_context);
void	engine_free_context(t_truc *ui_context);

#endif
