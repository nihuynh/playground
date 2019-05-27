/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:31:37 by nihuynh           #+#    #+#             */
/*   Updated: 2019/05/26 21:15:59 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "engine_struct.h"

t_engine	*get_engine(t_engine *engine_ptr);
void		realloc_pxl(t_engine *engine, int width, int height);

#endif
