File/Host network manager

IPv4 Address 192.168.57.1
IPv4 Network Mask 255.255.255.252

# Partition disk
        fdisk -l
or
        sudo fdisk -l

# Create a new user
        su - (Switch to the root user)
        adduser newuser
ou
        sudo useradd username

# Install sudo command
su -
apt-get(installation/desinstallation de paquet) install sudo -y

# give root privileges
        ip a newuser
        su newuser
        sudo whoami
or
        adduser username sudo

# Make sure you install ifupdown and resolvconf package
apt-get(installation/desinstallation de paquet) -y install ifupdown resolvconf

# enable host only adapter on Virtualbox
    Shut down the VM before setting adapter
    --> File/Host Network Manager/Create
    --> settings --> Adapter1 --> Enable Network Adapter
    --> settings --> Adapter2 --> Enable Network Adapter --> Attached to : Host-only Adapter

<!-- Service DHCP (Dynamic Host Configuration Protocol) =
un serveur (ou service) qui délivre des adresses IP aux ordinateurs qui se connectent sur le réseau. -->

# set a static IP
su -
nano /etc/network/interfaces

        # Interface Name
        auto enp0s3
        # Static IP Address (l’interface passe en static et non plus en dhcp)
        iface enp0s3 inet static
        # IP Address
        address 192.168.56.2
        # Netmask (permet de définir un sous-réseau afin de faciliter le routage ou le broadcast)
        netmask 255.255.255.252 (http://jodies.de/ipcalc netmask /30)
        # broadcast
        broadcast 192.168.56.3`

        auto enp0s8
        iface enp0s8 inet dhcp

service networking restart

ip a
https://www.itzgeek.com/how-tos/linux/debian/how-to-configure-static-ip-address-in-ubuntu-debian.html

<!-- SSH signifie Secure SHell. (connexion a distance)
C'est un protocole qui permet de faire des connexions sécurisées (i.e. cryptées) entre un serveur et un client SSH.
Nous allons utiliser le programme OpenSSH, qui est la version libre du client et du serveur SSH. -->

# Edit Port SSH for Linux server
nano /etc/ssh/sshd_config
        Inside this file find :
        Port 22
        Delete # et edit 22 by a new port number.
service sshd restart

# with publickeys
https://www.digitalocean.com/community/tutorials/how-to-set-up-ssh-keys--2
apt-get install keychain
ssh-keygen -t rsa (cree les cles publiques et prives)
ssh-copy-id newuser@192.168.56.2 -p 2222 (copie la cle ssh sur le serveur et la definir comme autorisee)
ssh -p 2222 newuser@192.168.56.2 (p = port)

# firewall configuration https://wiki.debian.org/iptables
sudo iptables -L //show configuration (default configuration with no filtering)
https://www.geek17.com/fr/content/debian-9-stretch-securiser-votre-serveur-avec-le-firewall-iptables-32

# Creer un fichier ipv6 /ipv4 (protocole de transport et de routage des paquets utilisé sur Internet)
*filter
:INPUT DROP [0:0]
:FORWARD DROP [0:0]
:OUTPUT DROP [0:0]

-A INPUT -m state --state ESTABLISHED,RELATED -j ACCEPT
-A OUTPUT -m state --state ESTABLISHED,RELATED -j ACCEPT

# http, https, DNS (Domain Name System =  service qui permet de traduire un nom de domaine (par exemple www.votre-organisation.com) en une adresse IP)
-A INPUT -p tcp --dport 80 -j ACCEPT <!-- Port http -->
-A OUTPUT -p tcp --dport 80 -j ACCEPT
-A INPUT -p tcp --dport 443 -j ACCEPT <!-- Port https -->
-A OUTPUT -p tcp --dport 443 -j ACCEPT
-A OUTPUT -p udp --dport 53 -j ACCEPT <!-- Port DNS -->

# ssh
-A INPUT -p tcp -m state --state NEW --dport 2222 -j ACCEPT
-A OUTPUT -p tcp -m state --state NEW --dport 2222 -j ACCEPT

COMMIT

** Enfin, on redémarre le service pour recharger et appliquer nos règles.
Le service s'appele netfilter-persistent, pas iptables...
sudo service netfilter-persistent restart
** Et on vérifie qu'elles ont bien été chargées.
sudo iptables -L

# Regles protection DDOS
<!-- Une attaque DDoS vise à rendre un serveur, un service ou une infrastructure indisponible. L'attaque peut prendre différentes formes : une saturation de la bande passante du serveur pour le rendre injoignable, un épuisement des ressources système de la machine, l'empêchant ainsi de répondre au trafic légitime. -->
https://sharadchhetri.com/2013/06/15/how-to-protect-from-port-scanning-and-smurf-attack-in-linux-server-by-iptables/
apt-get fail2ban (Fail2ban est un framework de prévention contre les intrusions)

https://www.maketecheasier.com/fail2ban-protect-apache-ddos/

# Port scan
https://www.it-connect.fr/bloquer-les-individus-qui-scannent-votre-machine-avec-portsentry/
apt-get install portsentry

# check if portsentry is working
tail -n 5 /var/log/syslog

# test scan port
sudo apt-get install nmap
nmap -v 192.168.56.1 -->(add ip)

# List services
sudo service --status-all

# stop service
sudo service XXX stop

# Ajout de tache planifiees
vim /etc/crontab
crontab -e
@reboot         root   	sh /root/update.sh
0  4    * * 1   root   	sh /root/update.sh
@midnight       root    sh /root/script.sh


# Installer mail
apt-get install mailutils

echo "Test" | mail -s "Test " root

# Signed certificat tuto
https://www.digitalocean.com/community/tutorials/how-to-create-a-self-signed-ssl-certificate-for-apache-in-debian-9