ssh -p '2222' 'skyline@127.0.0.1'
# check the crontab
sudo crontab -l


## List all the operations to get the VM set properly :
su root
apt-get update && apt-get upgrade && apt-get install -y sudo fail2ban portsentry nmap git vim mailutils
visudo
# => skyline ALL=(ALL) NOPASSWD: ALL

vim /etc/network/interfaces
# => iface enp0s3 static
# => address 10.0.2.0/30
# => gateway 10.0.2.2
# => dns-nameservers 10.51.1.42

sudo vim /etc/ssh/sshd_config
# => Port 2222
### on host :
ssh-keygen
cat skyline.pub | ssh skyline@127.0.0.1 -p 2222 "mkdir -p ~/.ssh && chmod 700 ~/.ssh && cat >>  ~/.ssh/authorized_keys"
cp skyline ~/.ssh/id_rsa && chmod 600 ~/.ssh/id_rsa
### on VM :
sudo vim /etc/ssh/sshd_config
# => AllowUsers skyline
# => PermitRootLogin no
# => PubkeyAuthentication yes
# => AuthorizedKeysFile	.ssh/authorized_keys .ssh/authorized_keys2
# => PasswordAuthentication no

sudo vim /etc/init.d/firewall
# => copy firewall service file
sudo crontab -e
# => @reboot		sudo service firewall start
# => @reboot		sh /home/skyline/update.sh
# => 00 4 * * 1	sh /home/skyline/update.sh
# => @midnight	sh /home/skyline/tracker.sh

sudo vim /home/skyline/update.sh

#!/bin/bash
LOGFILE="/var/log/update_script.log"
apt-get update -y > $LOGFILE
apt-get upgrade -y >> $LOGFILE

sudo vim /home/skyline/tracker.sh

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