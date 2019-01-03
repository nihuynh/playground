#!/bin/bash
LOGFILE="/var/log/update_script.log"
apt-get update -y > $LOGFILE
apt-get upgrade -y >> $LOGFILE