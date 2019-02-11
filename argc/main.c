/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 23:36:15 by nihuynh           #+#    #+#             */
/*   Updated: 2019/02/07 23:39:27 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int system_wide;

void usage() {}

void count_args(argc)
{
    printf("argc: %d\n", argc);
    if (argc == 5)
        system_wide = 1;
	else if (argc == 4)
       system_wide = 0;
   	else
       usage();
}

int main(int ac, char *av[])
{
    count_args();
    return (0);
}