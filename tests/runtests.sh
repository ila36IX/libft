#!/bin/bash
# This script meant to be run from outside this directory, it needs to be run
# within the directory where the test directory are exists

CYAN='\033[0;36m'
BLUE='\033[0;34m'
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

if [[ -z $func ]]; then
	echo "Please provide at least one function to test"
	exit 1
fi

if [[ $1 == "all" ]]; then
while read -r f; do
	if [[ -e "ft_$f.c" ]]; then
		if [[ -e "tests/test_ft_$f.c" ]]; then
			cc -g -Wall -Wextra -Werror -L. "tests/test_ft_$f.c" -lft -o runtests && ./runtests
		else
			echo -e "${BLUE}No test for '$f', yet!${NC}"
		fi
	else
		echo "Messing the file: ft_$f.c"
	fi
done < ./tests/functions.txt
else
	echo ""
	# It's important to use -e to allow backslash escapes.
	echo -e "${CYAN}>>>>> Testing ft_$func <<<<<${NC}"
	echo ""

	if [[ -e "ft_$func.c" ]]; then
		cc -g -Wall -Wextra -Werror -L. "tests/test_ft_$func.c" -lft -o runtests && ./runtests debug
	else
		echo "Messing the file: ft_$func.c"
	fi
fi


