#!/bin/bash
find . -name "*~" -delete -o -name ".DS_Store" -delete -o -name "#*#" -delete -o -name "*.dSYM" -exec rm -rf {} \;
find . -name "*.vscode" -exec rm -rf {} \;