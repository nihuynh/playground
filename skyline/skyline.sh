ssh -p '2222' 'skyline@127.0.0.1'

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


# check if portsentry is working
tail -n 5 /var/log/syslog
# test scan port
sudo apt-get install nmap
nmap -v 192.168.56.1 -->(add ip)

# List services
sudo service --status-all

# stop service
sudo service XXX stop
