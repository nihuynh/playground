#!/bin/bash
# The production directory
TARGET="/var/www/skyline.com/html"
# The local git
LOCAL="/home/skyline/playground/skyline/www"
sudo rm -rf $TARGET
sudo ln -sf $LOCAL $TARGET