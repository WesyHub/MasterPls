#include "list.h"
#include "starter.h"
#include <stdio.h>
#include <stdlib.h>


int main(void){

    pokemon *newpokemon = Read_csv();

    pokedex_menu(newpokemon);
    return 0;
}