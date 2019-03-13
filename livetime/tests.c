/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 01:54:39 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/13 02:34:31 by nihuynh          ###   ########.fr       */
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
	tab = lt_add(&lt, malloc(256 * sizeof(int)), free);
	tab1 = lt_add(&lt, malloc(256 * sizeof(int)), free);
	tab2 = lt_add(&lt, malloc(256 * sizeof(int)), free);
	tab3 = lt_add(&lt, malloc(256 * sizeof(int)), free);
	lt_print(lt);
	if (lt_destroy(lt))
		printf ("error durring destruct of the lt\n");
}

void	test_normal_detatch()
{
	t_lt	*lt;
	int		*tab;
	int		*tab1;
	int		*tab2;

	lt = NULL;
	tab = lt_add(&lt, malloc(256 * sizeof(int)), free);
	tab1 = lt_add(&lt, malloc(256 * sizeof(int)), free);
	tab2 = lt_add(&lt, malloc(256 * sizeof(int)), free);
	lt_print(lt);
	lt_detach(&lt, tab1);
	lt_detach(&lt, tab);
	lt_detach(&lt, tab2);
	if (lt_destroy(lt))
		printf ("error durring destruct of the lt\n");
}

void	test_error_print()
{
	t_lt	*lt;
	int		*tab;
	int		*tab1;
	int		*tab2;

	lt = NULL;
	tab = lt_add(&lt, malloc(256 * sizeof(int)), free);
	tab1 = lt_add(&lt, malloc(256 * sizeof(int)), free);
	tab2 = lt_add(&lt, malloc(256 * sizeof(int)), free);
	lt_print(lt);
	if (lt_destroy(lt))
		printf ("error durring destruct of the lt\n");
	lt_print(lt);
}

int main(void)
{

	// Normal Tests :
	//test_normal_case();
	test_normal_detatch(); while (42) ;

	// Errors Tests :
	//test_detatch_empty_lt();
	// test_detach_unexistant_data();

	// TODO Tests :
	//test_error_print();
}
