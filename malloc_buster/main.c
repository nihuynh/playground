/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 02:24:59 by nihuynh           #+#    #+#             */
/*   Updated: 2018/11/27 02:42:34 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>

void	leak(size_t size)
{
	void *leak;

	leak = malloc(size  * 1000);
}

int main(void)
{
	int timer;

	timer = 1000000;
	while (--timer > 0)
		leak(100);
	return (0);
}
