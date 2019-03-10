/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fibo_pool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 21:30:15 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/10 05:15:05 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pool.h"

int
	test1(void)
{
	t_pool	*thr_pool;

	thr_pool = pool_init(16);
	// pool_addtask(thr_pool, compute, NULL);
	pool_destroy(thr_pool);
	return (1);
}

int
	main(void)
{
	test1();
	return (1);
}
