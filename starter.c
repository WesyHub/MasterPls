#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "list.h"
#include "starter.h"

pokemon *pokedex = NULL;

pokemon *init(char *nom, char *type, int level, int nbown, char * discover, char * capture)
{
    pokemon *PTR_Controller = malloc(sizeof(*PTR_Controller));
    pokemon *PTR_Pokemon = malloc(sizeof(*PTR_Pokemon));

    if (PTR_Controller == NULL || PTR_Pokemon == NULL)
    {
        exit(EXIT_FAILURE);
    }

    PTR_Pokemon->nom = nom;
    PTR_Pokemon->type = type;
    PTR_Pokemon->level = level;
    PTR_Pokemon->nbown = nbown;
    PTR_Pokemon->capture = capture;
    PTR_Pokemon->discover = discover;
    PTR_Controller->first = PTR_Pokemon;
    PTR_Pokemon->next = NULL;

    return PTR_Controller;
}

pokemon *Read_csv(void){


    FILE *myfile = fopen("pokedex.csv", "r");
    
    pokemon *new_pokemon = NULL;
    
    pokemon *tmp_pokemon = NULL;
    
    char *ligne = NULL;
	size_t cpt = 0;

	getline(&ligne, &cpt, myfile);
	free(ligne);
	ligne = NULL;
	cpt = 0;
    int ini = 0;
    char* current_time = get_date();
	 



    if(ini !=0){
            pokeadd(new_pokemon, new_pokemon->nom, new_pokemon->type, new_pokemon->level, new_pokemon->nbown, new_pokemon->discover, new_pokemon->capture);
        }   
    else{
            pokemon* salameche_entry = malloc(sizeof(pokemon));
            salameche_entry->nom = "Salameche";
            salameche_entry->type = "Feu";
            salameche_entry->level = 5;
            salameche_entry->nbown = 1;
            salameche_entry->discover = current_time ;
            salameche_entry->capture = current_time ;
            salameche_entry->next = NULL;
            printf("\n");
            printf("Vous avez choisi %s ! \n", salameche_entry->nom);
            new_pokemon = salameche_entry;
            new_pokemon->next = NULL;
            ini =1;
        }
    
    if (myfile == NULL)
    {
        fprintf(stderr, "\nCouldn't Open File'\n");
        exit (1);
    }
    

    while (getline(&ligne, &cpt, myfile)!= -1){
        
        char *token;
        pokemon *new_node = malloc(sizeof(pokemon));

        ligne[strlen(ligne) - 1] = 0;

        token = strtok(ligne, ";");
        new_node->nom = malloc(sizeof(token)+1);
        strcpy(new_node->nom,token);
        
        token = strtok(NULL, ";");
        new_node->type = malloc(sizeof(token)+1);
        strcpy(new_node->type,token);
        
        new_node->level = atoi(strtok(NULL, ";"));
        new_node->nbown = atoi(strtok(NULL, ";"));

        token = strtok(NULL, ";");
        new_node->discover = malloc(sizeof(token)+1);
        strcpy(new_node->discover,token);

        token = strtok(NULL, ";");
        new_node->capture = malloc(sizeof(token)+1);
        strcpy(new_node->capture,token);
        
        
        new_node->next = NULL;

        if (tmp_pokemon != NULL)
        {
            tmp_pokemon->next = new_node;
        }
        
        tmp_pokemon = new_node;

        if (new_pokemon == NULL)
        {
            new_pokemon = tmp_pokemon ;
        }
        else
        {
            new_pokemon->next = tmp_pokemon;
            
        }
        
        free(ligne);
		ligne = NULL;
		cpt = 0;
        
    }
    
    fclose(myfile);
    return new_pokemon;
}

void adding_pokemon(pokemon *L)
{
    char nom[25];
    char type[25];
    int level = 2;
    char *current_time = get_date();


    printf("Nom : \n");
    scanf("%s", nom);
    printf("Type : \n");
    scanf("%s", type);
    printf("Level : \n");
    scanf("%d", &level);


    pokeadd(L, nom, type, level, 1, current_time, current_time);
    
}

void pokedex_menu(pokemon *L){
    
    while(1){
		int i = 0 ;

		printf("\n");
		printf("/*----------------------------------------------------------------------*/\n");
		printf("\n");
		printf("Ajouter un pokemon : 0\n");
		printf("Afficher le pokedex : 1\n");
		printf("Supprimer un pokemon : 2\n");
		printf("sauvegarder les pokemons : 3\n");
		printf("Quitter le programme : 4\n");

        scanf("%d", &i);

        if( i <= 4){

            void (*array_fptr[2])(pokemon *L);
            array_fptr[0] = &adding_pokemon;
            array_fptr[1] = &printList;
            array_fptr[i](L);
        }
        else {
            break;
        }
        pokedex = L;
    }

}

char* get_date(void){

	time_t mytime = time(NULL);
    char * time_str = ctime(&mytime);
    time_str[strlen(time_str)-1] = '\0';

    return time_str;

}



