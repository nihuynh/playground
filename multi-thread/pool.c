/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 02:15:37 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/10 05:14:47 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pool.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int
	ft_fibonacci(int index);

static void
	*compute(void *data)
{
	t_pool	*pool;
	int		task_id;
	int		res;

	pool = data;
	while (42)
	{
		// pull task
		pthread_mutex_lock(&(pool->count_mutex));
			pool->count++;
			task_id = pool->count;
		pthread_mutex_unlock(&(pool->count_mutex));
		// check end condition
		if (task_id > 46)
			return (data);
		// process pxl
		res = ft_fibonacci((int)task_id);
		// push data
		printf("The fibonacci of : %i\tas a result of : %i\n", task_id, res);
	}
	return (NULL);
}

t_pool
	*pool_init(int workers_count)
{
	t_pool	*pool;

	if (!(pool = malloc(sizeof(t_pool))))
		return (NULL);
	pool->workers_count = -1;
	pool->count = 0;
	if (!(pool->workers = malloc(sizeof(pthread_t) * workers_count)))
	{
		free(pool);
		return (NULL);
	}
	if (pthread_mutex_init(&(pool->count_mutex),NULL))
	{
		free(pool);
		return NULL;
	}
	while (++pool->workers_count < workers_count)
	{
		if (pthread_create(&(pool->workers[pool->workers_count]), NULL, compute, pool))
		{
			pool_destroy(pool);
			return (NULL);
		}
	}
	printf("pool successfully init\n");
	return (pool);
}

int
	pool_addtask(t_pool *pool, void* (*task) (void*), void *arg_task)
{
	(void)pool;
	task(arg_task);
	return (EXIT_SUCCESS);
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
	intptr_t	cthr;

	cthr = 0;
	while (cthr <= pool->workers_count)
	{
		pthread_join(pool->workers[cthr], NULL);
		cthr++;
	}
	free(pool->workers);
	free(pool);
	return (EXIT_SUCCESS);
}
