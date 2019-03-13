/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fibo_pool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 21:30:15 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/12 19:14:19 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pool.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int
	ft_fibonacci(int nb);

static void
	*compute(void *data)
{
	t_pool	*pool;
	int		task_id;
	int		res;

	pool = data;
	while (42)
	{
		pthread_mutex_lock(&(pool->count_mutex));
			task_id = pool->count;
			pool->count += 1;
		pthread_mutex_unlock(&(pool->count_mutex));
		if (task_id > 46)
			return (data);
		res = ft_fibonacci((int)task_id);
		printf("The fibonacci of : %i\tas a result of : %i\n", task_id, res);
	}
	return (NULL);
}

int
	test1(void)
{
	t_pool	*thr_pool;

	thr_pool = pool_init(16, compute, NULL);
	pool_wait(thr_pool);
	pool_destroy(thr_pool);
	return (1);
}

int
	main(void)
{
	test1();
	return (1);
}
