/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 02:15:37 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/11 04:03:54 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pool.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

t_pool
	*pool_init(int workers_count, void* (*task) (void*), void *task_arg)
{
	t_pool	*pool;

	if (!(pool = malloc(sizeof(t_pool))))
		return (NULL);
	pool->workers_count = -1;
	pool->count = 0;
	pool->task.task_function = task;
	pool->task.data = task_arg;
	if (!(pool->workers = malloc(sizeof(pthread_t) * workers_count)))
	{
		free(pool);
		return (NULL);
	}
	if (pthread_mutex_init(&(pool->count_mutex), NULL))
	{
		free(pool);
		return (NULL);
	}
	while (++pool->workers_count < workers_count)
	{
		if (pthread_create(&(pool->workers[pool->workers_count]), NULL, pool->task.task_function, pool))
		{
			pool_destroy(pool);
			return (NULL);
		}
	}
	printf("pool successfully init\n");
	return (pool);
}

int
	pool_wait(t_pool *pool)
{
	intptr_t	cthr;

	cthr = 0;
	while (cthr <= pool->workers_count)
	{
		pthread_join(pool->workers[cthr], NULL);
		cthr++;
	}
	printf("pool finish task\n");
	return (EXIT_SUCCESS);
}

int
	pool_destroy(t_pool *pool)
{
	if (pool->workers)
	{
		free(pool->workers);
		pthread_mutex_lock(&(pool->count_mutex));
        pthread_mutex_destroy(&(pool->count_mutex));
	}
	free(pool);
	return (EXIT_SUCCESS);
}
