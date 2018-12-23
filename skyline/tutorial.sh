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
# => @reboot sudo service firewall start
