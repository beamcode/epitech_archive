#!/usr/bin/env bash

find . -type f -name "*.o" -delete
find . -type f -name "~*" -delete
find . -type f -name "*.gcda" -delete
find . -type f -name "*.gcno" -delete
find . -type d -name "*.dSYM" -delete
find . -type d -name ".vscode" -delete
find . -type f -name ".DS_Store" -delete