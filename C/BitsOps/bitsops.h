/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitsops.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:07:51 by nihuynh           #+#    #+#             */
/*   Updated: 2020/11/09 16:12:55 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITSOPS_H
# define BITSOPS_H

# define BOOL(x) (!(!(x)))

/*
** Bool of the value of the nth bit :
*/

# define BIT_OP_TEST(data, n) BOOL(data & (1UL << (n)))

/*
** Set the value of the nth bit to 1 :
*/

# define BIT_OP_SET(data, n) (data |= (1UL << n))

/*
** Set the value of the nth bit to 0 :
*/

# define BIT_OP_CLR(data, n) (data &= ~(1UL << n))

/*
** Set the value of the nth bit to val :
*/

# define BIT_OP_ASSIGN(data, n, val) (data & ~(1UL << n)) | (val << n)

/*
** Flip the value of the nth bit :
*/

# define BIT_OP_TOGGLE(data, n) (data ^= (1UL << n))

/*
** Add 1 to the nth bit :
*/

# define BIT_OP_ADD(data, n) (data &= (1UL << n))

/*
** Print bits
*/

# include <stdio.h>
# define BIT_OP_PRINT(data)												\
	for(size_t i = (1UL << ((sizeof(data) * 8) - 1)); i > 0; i >>= 1)	\
	{putc((data & i) ? '1' : '0', stdout);};							\
	putc('\n', stdout)

#endif
