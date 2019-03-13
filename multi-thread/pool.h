/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 02:15:31 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/11 04:04:35 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POOL_H
# define POOL_H

#include <pthread.h>

# define	TPOOL_MAX_THR	64
# define 	TPOOL_MIN_THR	1


typedef struct		s_task
{
	void 			*(*task_function)(void*);
	void 			*data;
}					t_task;

typedef struct		s_pool
{
	int				count;
	int				workers_count;
	pthread_t		*workers;
	pthread_mutex_t	count_mutex;
	t_task			task;
}					t_pool;

t_pool				*pool_init(int workers_count, void* (*task) (void*), void *arg_task);
int					pool_wait(t_pool *pool);
int					pool_destroy(t_pool *pool);

#endif