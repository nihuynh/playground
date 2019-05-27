/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cimgui.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:58:36 by nihuynh           #+#    #+#             */
/*   Updated: 2019/05/26 22:55:53 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
# define GL_SILENCE_DEPRECATION

#include <SDL.h>
#include <stdbool.h>
#include "cimgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl2.h"

#if defined(__APPLE__)
# define GL_SILENCE_DEPRECATION
# include <OpenGL/gl.h>
#else
# include <GL/gl.h>
#endif

#include "engine_ui.h"
#include "engine.h"

t_truc	engine_hook_render(SDL_Window *window, t_img *img_ref)
{
	t_truc res;

	if (!(res.local_context = SDL_GL_CreateContext(window)))
		exit(EXIT_FAILURE);
	igCreateContext(NULL);
	ImGui_ImplSDL2_InitForOpenGL(window, &res.local_context);
	ImGui_ImplOpenGL2_Init();
	glGenTextures(1, &res.texture_id);
	glBindTexture(GL_TEXTURE_2D, res.texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	res.img_ref = img_ref;
	res.window = window;
	return (res);
}

void	engine_update_render(t_truc *ui_context)
{
	glBindTexture(GL_TEXTURE_2D, ui_context->texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ui_context->img_ref->width, ui_context->img_ref->height, 0, GL_BGRA, GL_UNSIGNED_BYTE, ui_context->img_ref->pixels);
	glBindTexture(GL_TEXTURE_2D, 0);
}

# define FLAGS1	ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar
# define FLAGS2	ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar
# define FLAGS3	ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoCollapse
# define FLAGS4	ImGuiWindowFlags_NoBringToFrontOnFocus
# define RENDER_FLAGS FLAGS1 | FLAGS2 | FLAGS3 | FLAGS4

void	spec_render_win(t_truc *ui_context)
{
	t_engine	*engine;

	(void)ui_context;
	engine = get_engine(NULL);
	igSetNextWindowPos((ImVec2){0, 0},  2, (ImVec2){0, 0});
	igBegin("specs render", NULL, ImGuiWindowFlags_NoScrollbar);
	igText("Resolution :	[app w:%i h:%i]", engine->vp_width, engine->vp_height);
	igText("Resolution :	[render w:%i h:%i]", engine->render_size.x, engine->render_size.y);
	igText("Resolution :	[img w:%i h:%i]", engine->img.width, engine->img.height);
	igDragInt("Render_scale", &engine->render_scale, 25, 25, 200, "%d%%");
	if (igButton("Apply", (ImVec2){130, 20}))
	{
		realloc_pxl(engine, (engine->render_scale * engine->render_size.x / 100), (engine->render_scale * engine->render_size.y / 100));
		engine->need_render = true;
	}
	if (igButton("Render new frame", (ImVec2){130, 20}))
		engine->need_render = true;
	igEnd();
}

void	render_win(t_truc *ui_context)
{
	ImVec2 size;
	t_engine	*engine;

	(void)ui_context;
	engine = get_engine(NULL);
	size.x = ui_context->img_ref->width;
	size.y = ui_context->img_ref->height;
	igSetNextWindowPos((ImVec2){0, 0},  2, (ImVec2){0, 0});
	igSetNextWindowSize((ImVec2){engine->render_size.x, engine->render_size.y}, 0);
	igPushStyleVarVec2(ImGuiStyleVar_WindowPadding, (ImVec2){0, 0});
	igPushStyleVarFloat(ImGuiStyleVar_WindowRounding, 0);
	igBegin("render", NULL, RENDER_FLAGS);
	igImage((void*)(intptr_t)ui_context->texture_id, (ImVec2){engine->render_size.x, engine->render_size.y},
		(ImVec2){0, 0}, (ImVec2){1, 1}, (ImVec4){1, 1, 1, 1},
		(ImVec4){0, 0, 0, 0});
	igEnd();
	igPopStyleVar(2);
}

void	engine_ui(t_truc *ui_context)
{
	ImGuiIO *io;

	io = igGetIO();
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplSDL2_NewFrame(ui_context->window);
	igNewFrame();
	// all the interface are declare here
	render_win(ui_context);
	spec_render_win(ui_context);
	igShowDemoWindow(NULL);
	igRender();
	glViewport(0, 0, (int)io->DisplaySize.x, (int)io->DisplaySize.y);
	glClearColor(0.107f, 0.277f, 0.348f, 1.000f);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL2_RenderDrawData(igGetDrawData());
	SDL_GL_SwapWindow(ui_context->window);
}

void	engine_free_context(t_truc *ui_context)
{
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
	igDestroyContext(ui_context->imgui_context);
	SDL_GL_DeleteContext(ui_context->local_context);
}
