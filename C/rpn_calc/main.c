/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 10:07:07 by exam              #+#    #+#             */
/*   Updated: 2018/12/04 11:49:04 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define OPERATOR(c)	(c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
#define DIGIT(c)	(c >= 48 && c <= 57)
#define VALID(c)	(OPERATOR(c) || DIGIT(c) || c == 32)

int	error_msg(void)
{
	printf("Error\n");
	return (-1);
}

int	error_check(char *str)
{
	while (*str)
	{
		if (!VALID(*str))
			return (-1);
		str++;
	}
	return (0);
}

int	do_op(int a, int b, char o)
{
	if (o == 43)
		return (a + b);
	if (o == 45)
		return (a - b);
	if (o == 42)
		return (a * b);
	if (o == 47)
		return (a / b);
	return (a % b);
}

int	rpn_calc(char *str)
{
	int stack[4096];
	int idx;

	idx = 0;
	while (*str)
	{
		if (OPERATOR(*str))
		{
			if (idx < 2)
				return (error_msg());
			stack[idx - 2] = do_op(stack[idx - 2], stack[idx - 1], *str);
			idx--;
		}
		if (DIGIT(*str))
			stack[idx++] = atoi(str);
		while (DIGIT(*str))
			str++;
		str++;
		while (*str == 32)
			str++;
	}
	if (idx != 1)
		return (error_msg());
	printf("%d\n", stack[0]);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (error_msg());
	if (error_check(av[1]) == -1)
		return (error_msg());
	return (rpn_calc(av[1]));
}
