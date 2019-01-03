#!/bin/bash
# https://blog.jolos.fr/2017/02/envoyer-des-mails-en-ligne-de-commande-debian-8/
# apt-get install -y ssmtp mailutils
OLD=/etc/crontab.old
CURRENT=/etc/crontab
if [ ! -f $OLD ]
then
	cp $CURRENT $OLD
	exit
fi

if [ $(md5sum $OLD | cut -d ' ' -f 1) != $(md5sum $CURRENT | cut -d ' ' -f 1) ]
then
	echo "Crontab has been modified" | mail -s "Alert: Crontab modif $HOST" root
fi
cp $CURRENT $OLD