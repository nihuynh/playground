/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:28:26 by nihuynh           #+#    #+#             */
/*   Updated: 2019/07/22 12:34:02 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "libft.h"

int	ft_ls(char *path)
{
	struct dirent	*d;
	DIR 			*dir;

	if (!(dir = opendir(path)))
		return (EXIT_FAILURE);
	while ((d = readdir(dir))
	{
		printf("%s\n", d->d_name);
	}
	return (EXIT_SUCCESS);
}

int main(int ac, char const *av[])
{
	if (ac == 2)
		return (ft_ls(av[1]));
	return (EXIT_SUCCESS);
}
