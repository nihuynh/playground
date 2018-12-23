#!/bin/bash
# https://javapipe.com/blog/iptables-ddos-protection/
# https://gist.github.com/pr0dukter/9c066b1b4e586a71ca13b29131505cff

# reset the config
/sbin/iptables -F
/sbin/iptables -X
/sbin/iptables -P INPUT DROP
/sbin/iptables -P FORWARD DROP
/sbin/iptables -P OUTPUT DROP

# Allow input for the services
/sbin/iptables -A INPUT  -m state --state ESTABLISHED,RELATED  -j ACCEPT
/sbin/iptables -A INPUT -p tcp -m multiport --dports 80,443,2222 -j ACCEPT
/sbin/iptables -A OUTPUT  -m state --state ESTABLISHED,RELATED  -j ACCEPT
/sbin/iptables -A OUTPUT -p tcp -m multiport --dports 80,443,2222 -j ACCEPT

# Allow DNS
iptables -A OUTPUT --protocol udp --destination-port 53 -j ACCEPT

#Autoriser sortie FTP
iptables -A OUTPUT -p tcp --dport 21 -j ACCEPT
iptables -A OUTPUT -p tcp --dport 20 -j ACCEPT