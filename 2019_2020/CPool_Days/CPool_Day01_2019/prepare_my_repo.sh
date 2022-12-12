#!/bin/bash
blih -u samuel.palmer@epitech.eu repository create $1
blih -u samuel.palmer@epitech.eu repository setacl $1 ramassage-tek r
blih -u samuel.palmer@epitech.eu repository getacl $1