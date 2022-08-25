#include "list.h"
#include "starter.h"
#include <stdio.h>
#include <stdlib.h>
#include "signal.h"
#include <signal.h>


int main(void){

    signal(SIGINT, quit_signal);
    signal(SIGUSR1, save_auto);
    pokemon *newpokemon = Read_csv();
    pokedex_menu(newpokemon);
    return 0;
}