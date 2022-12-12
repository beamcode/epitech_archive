##
## EPITECH PROJECT, 2019
## skip-synthesis.sh
## File description:
## requirements
##

#!/bin/sh
awk '{print $3,"\t",$9}' | grep \ $1