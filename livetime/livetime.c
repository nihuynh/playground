/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   livetime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 02:30:46 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/13 02:36:52 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include "livetime.h"


void	*lt_add(t_lt **lt, void *data, void destruct(void *))
{
	t_lt *node;

	if (data != NULL)
	{
		if (!(node = (t_lt*)malloc(sizeof(t_lt))))
			return (NULL);
		node->next = *lt;
		node->destruct = destruct;
		node->data = data;
		*lt = node;
		return (data);
	}
	lt_destroy(*lt);
	return (NULL);
}

t_lt	*lt_get(t_lt *lt, t_lt **prev_lt, void *data)
{
	while (lt != NULL && lt->data != data)
	{
		*prev_lt = lt;
		lt = lt->next;
	}
	return (lt);
}

int		lt_detach(t_lt **lt, void *data)
{
	t_lt *prev_lt;
	t_lt *wanted_lt;

	prev_lt = NULL;
	if (!(wanted_lt = lt_get(*lt, &prev_lt, data)))
		return (1);
	if (prev_lt != NULL)
		prev_lt->next = wanted_lt->next;
	else
		*lt = wanted_lt->next;
	free(wanted_lt);
	return (0);
}

int		lt_destroy(t_lt *lt)
{
	t_lt *next_lt;

	if (!(lt))
		return (1);
	while (lt != NULL)
	{
		lt->destruct(lt->data);
		next_lt = lt->next;
		free(lt);
		lt = next_lt;
	}
	return (0);
}

int		lt_print(t_lt *lt)
{
	while (lt != NULL)
	{
		printf ("Address => lt_frame :%p\tdata :%p\tlt_next :%p\n", lt, lt->data, lt->next);
		lt = lt->next;
	}
	return (0);
}
