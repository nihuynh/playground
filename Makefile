# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 18:10:56 by nihuynh           #+#    #+#              #
#    Updated: 2019/03/23 20:18:41 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clean :
	@find . -name "*.out" -print -delete
	@find . -name "*.o" -print -delete
	@find . -name "*.s" -print -delete
.PHONY: clean