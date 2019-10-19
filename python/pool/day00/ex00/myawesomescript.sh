#!/usr/bin/env bash
curl -s $1 | grep href | cut -d '"' -f 2
