/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 20:35:11 by nihuynh           #+#    #+#             */
/*   Updated: 2019/05/26 18:55:58 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "engine_struct.h"
# include "engine_ui.h"

int		engine_free(t_engine *engine)
{
	int idx;

	idx = -1;
	if (engine->handle != NULL)
		free(engine->handle);
	if (engine->win != NULL)
		SDL_DestroyWindow(engine->win);
	if (engine->threads != NULL)
	{
		free((void*)engine->threads);
		engine->threads = NULL;
	}
	if (engine->img.pixels)
		free(engine->img.pixels);
	SDL_Quit();
	free(engine);
	return (EXIT_SUCCESS);
}
