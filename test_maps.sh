#!/bin/bash

printf "\e[32mDo you want to run valgrind with the tests? (y/n) \e[0m"
read yn
if [[ $yn =~ ^[Yy]$ ]]
then
	printf "\nRunning so long with valgrind...\n\n"
	VALGRIND="valgrind --leak-check=full --show-leak-kinds=all"
else
	VALGRIND=
fi


printf "Opening map with 2 exits.\n\n"
$VALGRIND ./so_long maps/2exits.ber
printf "\n\n"
printf "\e[32mPress enter to continue\e[0m."
read 

printf "Opening map with 2 players.\n\n"
$VALGRIND ./so_long maps/2players.ber
printf "\n\n"
printf "\e[32mPress enter to continue\e[0m."
read 

printf "Opening map that isn't a rectangular shape.\n\n"
$VALGRIND ./so_long maps/line_size.ber
printf "\n\n"
printf "\e[32mPress enter to continue\e[0m."
read 

printf "Opening map without collectibles.\n\n"
$VALGRIND ./so_long maps/no_clt.ber
printf "\n\n"
printf "\e[32mPress enter to continue\e[0m."
read 

printf "Opening map without an exit.\n\n"
$VALGRIND ./so_long maps/no_exit.ber
printf "\n\n"
printf "\e[32mPress enter to continue\e[0m."
read 

printf "Opening map without a path to exit.\n\n"
$VALGRIND ./so_long maps/no_path.ber
printf "\n\n"
printf "\e[32mPress enter to continue\e[0m."
read 

printf "Opening map without a path to a collectible.\n\n"
$VALGRIND ./so_long maps/no_path_clt.ber
printf "\n\n"
printf "\e[32mPress enter to continue\e[0m."
read 

printf "Opening map without a player.\n\n"
$VALGRIND ./so_long maps/no_plr.ber
printf "\n\n"
printf "\e[32mPress enter to continue\e[0m."
read 

printf "Opening map not surrounded by walls.\n\n"
$VALGRIND ./so_long maps/no_wall.ber
printf "\n\n"
printf "\e[32mPress enter to continue\e[0m."
read 

printf "Opening map with a wrong character.\n\n"
$VALGRIND ./so_long maps/wrong_char.ber
printf "\n\n"
printf "\e[32mPress enter to continue\e[0m."
read 

printf "Starting maps that work...\n"

printf "Opening map square shape (3x3).\n\n"
$VALGRIND ./so_long maps/square.ber
printf "\n\n"
printf "\e[32mPress enter to continue\e[0m."
read 

printf "Opening rectangular map on a vertical.\n\n"
$VALGRIND ./so_long maps/rectangular_vert.ber
printf "\n\n"
printf "\e[32mPress enter to continue\e[0m."
read 

printf "Opening map test 1.\n\n"
$VALGRIND ./so_long maps/test.ber
printf "\n\n"
printf "\e[32mPress enter to continue\e[0m."
read 

printf "Opening map test 2.\n\n"
$VALGRIND ./so_long maps/test2.ber
printf "\n\n"
printf "\e[32mPress enter to continue\e[0m."
read 

printf "Opening map test 3.\n\n"
$VALGRIND ./so_long maps/test3.ber
printf "\n\n"
printf "End of tests.\n"
