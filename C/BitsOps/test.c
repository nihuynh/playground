/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:51:27 by nihuynh           #+#    #+#             */
/*   Updated: 2020/11/09 16:15:21 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitsops.h"

#define TYPE_TESTED char

void	test_test()
{
	TYPE_TESTED 	data;
	int				len;

	data = 0;
	len = sizeof(data) * 8;
	printf("%s has started\n", __func__);
	while (--len >= 0)
	{
		if (BIT_OP_TEST(data, len))
			return ;
	}
	printf("%s is a success\n", __func__);
}

void	test_set()
{
	TYPE_TESTED 	data;
	TYPE_TESTED 	res;
	int				len;

	data = 0;
	res = ~(data);
	len = sizeof(data) * 8;
	printf("%s has started\n", __func__);
	BIT_OP_PRINT(data);
	while (--len >= 0)
		BIT_OP_SET(data, len);
	BIT_OP_PRINT(data);
	if (data == res)
		printf("%s is a success\n", __func__);
}

void	test_clr()
{
	printf("%s has started\n", __func__);
	// Do test
		return ;
	printf("%s is a success\n", __func__);
}

void	test_assign()
{
	printf("%s has started\n", __func__);
	// Do test
		return ;
	printf("%s is a success\n", __func__);
}
void	test_toggle()
{
	printf("%s has started\n", __func__);
	// Do test
		return ;
	printf("%s is a success\n", __func__);
}

void	test_add()
{
	printf("%s has started\n", __func__);
	// Do test
		return ;
	printf("%s is a success\n", __func__);
}


int main (void)
{
	test_test();
	test_set();
	test_clr();
	test_assign();
	test_toggle();
	test_add();
	return (0);
}