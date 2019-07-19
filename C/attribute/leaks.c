/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:22:39 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/15 01:06:03 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

// __attribute__((destructor))
void clean(void)
{
	printf("Clean-up\n");
	while (1)
		;
}

int remain(void)
{
	char *data;
	data = strdup("Hello!\n");
	printf("%s", data);
	printf("How are you?\n");
	exit(EXIT_FAILURE);
	return (0);
}

int main(void)
{
	atexit(clean);
	remain();
	return (0);
}