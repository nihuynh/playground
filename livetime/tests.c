/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 01:54:39 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/14 21:18:39 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <stdio.h>
# include "livetime.h"

void	test_normal_case()
{
	t_lt	*lt;
	int		*tab;
	int		*tab1;
	int		*tab2;
	int		*tab3;

	lt = NULL;
	tab = lt_add(&lt, malloc(256 * sizeof(int)), free, EXIT_ONFAIL);
	tab1 = lt_add(&lt, malloc(256 * sizeof(int)), free, EXIT_ONFAIL);
	tab2 = lt_add(&lt, malloc(256 * sizeof(int)), free, EXIT_ONFAIL);
	tab3 = lt_add(&lt, malloc(256 * sizeof(int)), free, EXIT_ONFAIL);
	if (lt_destroy(&lt))
		printf("error durring destruct of the lt\n");
}

void	test_normal_detatch()
{
	t_lt	*lt;
	int		*tab;
	int		*tab1;
	int		*tab2;

	lt = NULL;
	tab = lt_add(&lt, malloc(256 * sizeof(int)), free, EXIT_ONFAIL);
	tab1 = lt_add(&lt, malloc(256 * sizeof(int)), free, EXIT_ONFAIL);
	tab2 = lt_add(&lt, malloc(256 * sizeof(int)), free, EXIT_ONFAIL);
	lt_detach(&lt, tab1);
	lt_detach(&lt, tab);
	lt_detach(&lt, tab2);
	lt_destroy(&lt);
	free(tab);
	free(tab1);
	free(tab2);
}

void	test_detatch_empty_lt()
{
	t_lt	*lt;
	int		*tab;
	int		*tab1;

	lt = NULL;
	tab = lt_add(&lt, malloc(256 * sizeof(int)), free, EXIT_ONFAIL);
	tab1 = malloc(256 * sizeof(int));
	lt_detach(&lt, tab1);
	if (lt_destroy(&lt))
		printf("error durring destruct of the lt\n");
}

void	test_double_destroy()
{
	t_lt	*lt;
	int		*tab;
	int		*tab1;

	lt = NULL;
	tab = lt_add(&lt, malloc(256 * sizeof(int)), free, EXIT_ONFAIL);
	tab1 = lt_add(&lt, malloc(256 * sizeof(int)), free, EXIT_ONFAIL);
	if (lt_destroy(&lt))
		printf("error durring destruct of the lt\n");
	if (lt_destroy(&lt))
		printf("error during destruct2 of the lt\n");
}

void	test_destroy_empty()
{
	t_lt	*lt;

	lt = NULL;
	if (lt_destroy(&lt))
		printf("error durring destruct of the lt\n");
}

int main(void)
{

	// Normal Tests :
	// test_normal_case();
	// test_normal_detatch();

	// Errors Tests :
	// test_detatch_empty_lt();
	test_double_destroy();
	test_destroy_empty();
	while (42) ;
	return (0);
}
