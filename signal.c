#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "list.h"
#include "starter.h"

extern pokemon *pokedex;

/*----------------------------------------------------------------------*/


void quit_signal(int sig){

	int i = 0; 

	signal(sig, SIG_IGN);
	signal(SIGINT, quit_signal);

	printf("Voulez vous vraiment quitter le programe \n");
	printf("Oui : 0\n");
	printf("Non : 1\n");

	scanf("%d",&i);

	if( i == 0){
		quit(pokedex);
	}

	else{

		return pokedex_menu(pokedex);
	}

	raise(SIGINT);

}

/*----------------------------------------------------------------------*/

void save_auto(int sig){

	int i = 0;
	signal(sig, SIG_IGN);
	signal(SIGUSR1, save_auto);
	
	printf("Sauvegarde rapide ? \n");
	printf("Oui : 0\n");
	printf("Non : 1\n");

	scanf("%d",&i);

	if( i == 0){
		save(pokedex);
		return pokedex_menu(pokedex);
	}

	else{

		return pokedex_menu(pokedex);
	}
	
	raise(SIGUSR1);
}

/*----------------------------------------------------------------------*/