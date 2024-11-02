#!/bin/env bash
# This script meant to be run from outside this directory, it needs to be run
# within the directory where the test directory are exists

CYAN='\033[0;36m'
NC='\033[0m'

echo "▄▄▄▄▄▄▄▄▄ ..▄▄ · ▄▄▄▄▄▪   ▐ ▄  ▄▄ •       "
sleep 0.05
echo "▀•██ ▀▀▄.▀·▐█ ▀. •██  ██ •█▌▐█▐█ ▀ ▪      "
sleep 0.04
echo "  ▐█.▪▐▀▀▪▄▄▀▀▀█▄ ▐█.▪▐█·▐█▐▐▌▄█ ▀█▄      "
sleep 0.03
echo "  ▐█▌·▐█▄▄▌▐█▄▪▐█ ▐█▌·▐█▌██▐█▌▐█▄▪▐█      "
sleep 0.02
echo "  ▀▀▀  ▀▀▀  ▀▀▀▀  ▀▀▀ ▀▀▀▀▀ █▪·▀▀▀▀ ▀ ▀ ▀ "
sleep 0.2

func=$1
if [[ -z $func ]]; then
	echo "Please provide at least one function to test"
	exit 1
fi

echo ""
# It's important to use -e to allow backslash escapes.
echo -e "${CYAN}>>>>> Testing ft_$func <<<<<${NC}"
echo ""

if [[ -e "ft_$func.c" ]]; then
	gcc -Wall -Wextra -Werror "ft_$func.c" "tests/test_ft_$func.c" -o runtests && ./runtests
else
	echo "Messing the file: ft_$func.c"
fi

