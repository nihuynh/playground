/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   livetime.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 00:25:07 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/13 02:33:09 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFETIME_H
# define LIFETIME_H

typedef struct s_lt	t_lt;

struct				s_lt
{
	void			*data;
	void			(*destruct)(void *);
	t_lt			*next;
};

void				*lt_add(t_lt **lt, void *data, void destruct(void *));
int					lt_detach(t_lt **lt, void *data);
int					lt_destroy(t_lt *lt);
int					lt_print(t_lt *lt);

#endif