#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "starter.h"


extern pokemon *pokedex;

void printList(pokemon *L)
{
    if (L == NULL)
    {
        printf("Aucun pokemon à afficher\n");
    }
    else 
        {
        while (L)
            {  
                
                printf("\nNom du pokemon : %s\nType: %s\nNiveau : %d\nNombre d'exemplaire : %d\nDate de découverte : %s\nDate de capture : %s\n", L->nom, L->type, L->level, L->nbown, L->discover, L->capture);
                L = L->next;
            }
        }
    
    
}

void pokeadd(pokemon *L, char *nom, char *type, int level, int nbown, char *discover, char *capture)
{



    pokemon *new_pokemon = malloc(sizeof(pokemon));
    if (L == NULL || new_pokemon == NULL)
    {
        exit(EXIT_FAILURE);
    }
    // new_pokemon->nom = nom;
    new_pokemon->nom = malloc(strlen(nom) + 1);
    strcpy(new_pokemon->nom, nom);
    new_pokemon->type = malloc(strlen(type) + 1);
    strcpy(new_pokemon->type, type);
    new_pokemon->level = level;
    new_pokemon->nbown = nbown;
    new_pokemon->capture = capture;
    new_pokemon->discover = discover;
    new_pokemon->next = NULL;
    // L->next = new_pokemon;
    // printList(L);
    if(L == NULL)
    {
        L = new_pokemon;
        return;
    }
   
    while (L->next != NULL)
    {
        L = L->next;

    }
    L->next = new_pokemon;
    
   
   

    
    
    
    return;
}
int get_lenght(pokemon * L){

	int count;

	while(L != NULL){

		L = L->next;
		count ++ ; 
	} 

	return count - 1;
}

int get_index(pokemon *L, int lenght, char * pokemon_search){

	int index = 0; 

	for(int i = 0; i < lenght && L != NULL; i++){

		char * pokemon_pokedex = L->nom;

		if(strcmp(pokemon_pokedex,pokemon_search) == 0 ){

				index = i;
						
		}
		
		
		L= L->next;
	}


	return index;
}

void update_element(pokemon *L, int index , int old_value, int new_value, char* capture){
	

	pokemon *head = L;
	pokemon *current = NULL;

	int position = 0; 

	if(head == NULL){

		return;
	}

	current = head;

	for(int i = 0; index; i++){	

		if(current->nbown == old_value){

			current->nbown = new_value;
			current->capture = capture;
			
			return;
		}

		current = current->next;
		position ++ ;
	} 

	pokedex_menu(L);
}

/*----------------------------------------------------------------------*/

int exist_pokemon(pokemon *L, char *nom){

	while(L != NULL){

		char* pokemon_pokedex = L->nom;

		printf("#----%s-----#\n",pokemon_pokedex);
			
		if(strcmp(nom, pokemon_pokedex) == 0){

			return(1);		
		}
		
		L = L->next;		
	}

	return(0);
}

/*----------------------------------------------------------------------*/

void print_specific_pokemon(pokemon *L){

	char pokemon_search [15];

	int i = 0;

	printf("Par nom : 0 \n");
	printf("Attrapé : 1\n");
	printf("Apercu : 2\n");
	printf("Retour : 3\n");

	scanf("%d",&i);

	if(i == 0){

		printf("Saisissez le nom du pokemon : ");
		scanf("%s",pokemon_search);
		printf("#----%s-----#\n",pokemon_search);

		while(L != NULL){

		char* pokemon_pokedex = L->nom;

		printf("#----%s-----#\n",pokemon_pokedex);
			
		if(strcmp(pokemon_search, pokemon_pokedex) == 0){

			printf("\n");
			printf("#---Information sur le Pokemon---#\n");
			printf("\n");
			printf("Nom du Pokemon : %s\n",L->nom);
			printf("Type du Pokemon : %s\n",L->type);
			printf("Niveau du pokemon : %d\n",L->level);
			printf("Date de decouverte du pokemon : %s\n",L->discover);
			printf("Date de capture du pokemon : %s\n", L->capture);
			printf("Nombre de fois capturé : %d\n",L->nbown);		
		}
			
		L = L->next;

		}
	}

	else if(i == 1){

		int statue = 1 ;

		while(L != NULL){

			int possede = L->nbown;

			if(possede >= statue){

				printf("\n");
				printf("#---Information sur le Pokemon---#\n");
				printf("\n");
				printf("Nom du Pokemon : %s\n",L->nom);
				printf("Type du Pokemon : %s\n",L->type);
				printf("Niveau du pokemon : %d\n",L->level);
				printf("Date de decouverte du pokemon : %s\n",L->discover);
				printf("Date de capture du pokemon : %s\n", L->capture);
				printf("Nombre de fois capturé : %d\n",L->nbown);
			}

		L = L->next;

		}
	}

	else if(i == 2){

		int statue = 0 ;

		while(L != NULL){

			int possede = L->nbown;

			if(statue == possede){

				printf("Nom du Pokemon : %s\n",L->nom);
				printf("Type du Pokemon : %s\n",L->type);
				printf("Niveau du pokemon : %d\n",L->level);
				
			}

		L = L->next;

		}
	}	
}

void delete_pokemon_node(pokemon *L, int index){


	pokemon *prev, *tmp;
    int i;

    if(L == NULL || index < 0){ 
    	return ;
    }

    if(index == 0){

    	printf("index : %d", index);
        tmp = L->next;
        free(L);
        L = NULL;
	} 

    else {

        prev = L;
        tmp = L->next;

        for(i=1;i<index;++i){
            
            prev = tmp;
            tmp = tmp->next;
            
            if(tmp == NULL){
            	return ;
            }
        }

        prev->next = tmp->next;
        free(tmp);
        tmp = NULL;
    }
}