/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fibo_mono.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 21:30:15 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/10 05:14:57 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_fibonacci(int index);

void	compute(int i)
{
	printf("\nThe fibonacci of : %i\tas a result of : %i", i, ft_fibonacci(i));
}

int		main(void)
{
	int	index;

	index = 0;
	while (index < 47)
	{
		compute(index);
		index++;
	}
	return (0);
}
