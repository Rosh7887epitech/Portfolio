#!/bin/bash
cut -d ":" -f1 | tail -n +2 | sed -n "1~2p" | rev | sort  -r | sed -n "${MY_LINE1} , ${MY_LINE2}p" | sed -z 's/\n/, /g' | sed 's/, $/.\n/g'
