/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitsops.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:07:51 by nihuynh           #+#    #+#             */
/*   Updated: 2019/04/03 15:52:50 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITSOPS_H
# define BITSOPS_H

#include <stdio.h>

typedef enum {ERROR = -1, FALSE, TRUE} LOGICAL;

#define BOOL(x) (!(!(x)))

// Bool of the value of the nth bit :
# define BIT_OP_TEST(data, n) BOOL(data & (1UL << (n)))

// Set the value of the nth bit to 1 :
# define BIT_OP_SET(data, n) (data |= (1UL << n))

// Set the value of the nth bit to 0 :
# define BIT_OP_CLR(data, n) (data &= ~(1UL << n))

// Set the value of the nth bit to val :
# define BIT_OP_ASSIGN(data, n, val) (data & ~(1UL << n)) | (val << n)

// Flip the value of the nth bit :
# define BIT_OP_TOGGLE(data, n) (data ^= (1UL << n))

// Add 1 to the nth bit :
# define BIT_OP_ADD(data, n) (data &= (1UL << n))

// Print bits
# define BIT_OP_PRINT(data)											\
	for(size_t i = (1 << ((sizeof(data) * 8) - 1)); i > 0; i >>= 1)	\
	{putc((data & i) ? '1' : '0', stdout);};						\
	putc('\n', stdout)

#endif