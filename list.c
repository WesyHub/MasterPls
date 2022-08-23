#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


