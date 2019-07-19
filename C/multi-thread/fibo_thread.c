/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fibo_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 21:30:15 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/10 05:15:19 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int		ft_fibonacci(int index);

static inline void	*compute(void *i)
{
	printf("\nThe fibonacci of : %i\tas a result of : %i", \
			(int)i, ft_fibonacci((int)i));
	return (NULL);
}

int					main(void)
{
	intptr_t	cthr;
	int			status;
	pthread_t	toby[47];

	cthr = 0;
	status = 0;
	while (cthr <= 46 && !status)
	{
		status = pthread_create(&toby[cthr], NULL, compute, (void *)cthr);
		cthr++;
	}
	cthr = 0;
	while (cthr <= 46)
	{
		pthread_join(toby[cthr], NULL);
		cthr++;
	}
	return (EXIT_SUCCESS);
}
