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

git clone https://github.com/nihuynh/playground.git

sudo cp playground/skyline/scripts/firewall_service /etc/init.d/firewall
sudo cp playground/skyline/scripts/firewall.sh /home/skyline
sudo cp playground/skyline/scripts/update.sh /home/skyline
sudo cp playground/skyline/scripts/tracker.sh /home/skyline
sudo echo "sshd: ALL" >> /etc/hosts.allow


sudo crontab -e
# => @reboot		sudo service firewall start
# => @reboot		sh /home/skyline/update.sh
# => 00 4 * * 1	sh /home/skyline/update.sh
# => @midnight	sh /home/skyline/tracker.sh

# Set Apache

sh playground/skyline/scripts/deploy.sh


### Correction command :

history
cat /etc/ssh/sshd_config /etc/network/interfaces && crontab -l
sudo crontab -l && fdisk -l && iptables -L && service --status-all && apt-get update
### Links :
https://odan.github.io/2017/10/29/accessing-your-virtualbox-guest-from-your-host-os.html
