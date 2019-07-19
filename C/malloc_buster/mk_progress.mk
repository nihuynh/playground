# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mk_progress.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/16 19:01:52 by nihuynh           #+#    #+#              #
#    Updated: 2019/07/17 13:48:36 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef PROGRESS
# T estimates how many targets we are building for the PROGRESS.
T	:=	$(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
        -rRf $(firstword $(MAKEFILE_LIST)) \
        PROGRESS="echo COUNTTHIS" BUILD="test x ||" | grep -c "COUNTTHIS")
N	:=	x
C	=	$(words $N)$(eval N := x $N)
PROGRESS = "[`expr $C '*' 100 / $T`%]"
endif
