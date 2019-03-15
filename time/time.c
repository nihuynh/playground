/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 02:07:25 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/15 02:22:22 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>

static inline long get_current_usec() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000000 + time.tv_usec);
}

int main() {
	int		i;
	long	elapsed_time;

	elapsed_time = get_current_usec();
	i = -1;
	while(++i < 10000000)
	{
		i--;
		i++;
	}
	elapsed_time = get_current_usec() - elapsed_time;
	printf("It took %ld useconds to complete the task.\n", elapsed_time);
	return (0);
}
