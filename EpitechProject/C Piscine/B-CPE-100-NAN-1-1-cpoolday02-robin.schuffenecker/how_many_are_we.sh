#!/usr/bin/env bash
cut -d ";" -f 3 > city
cat city | grep -i "$1" | wc -l
