# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sync.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/17 10:40:34 by nihuynh           #+#    #+#              #
#    Updated: 2018/02/22 21:14:39 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh
BASEDIR=$(dirname "$0")
SRCDIR="/Users/nihuynh/Work"
DESTDIR="/Users/nihuynh/Bucket/42"

rsync -avn --delete --progress --exclude "a.out" --exclude ".git" --exclude ".DS_Store" $SRCDIR $DESTDIR > $BASEDIR/sync.log &&
   	cat $BASEDIR/sync.log | less &&

# Ask for confirmation :
read -p "Continue to sync the folders ? (y / n)?" &&
if [[ $REPLY = [yY] ]]
then
{
 	rsync -av --delete --progress --exclude "a.out" --exclude ".git" --exclude ".DS_Store" $SRCDIR $DESTDIR &&
	cd $BASEDIR && git add -A && git commit -m $(date +"%m-%d-%y/%T") && git push >> $BASEDIR/sync.log &&
	echo "Done"
}
fi
