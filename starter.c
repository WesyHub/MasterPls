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
pokemon *bulbizarre(void){

	char* current_time = get_date();

	pokemon* bulbizarre_entry = malloc(sizeof(pokemon));
	bulbizarre_entry->nom = "Bulbizarre";
	bulbizarre_entry->type = "Plante";
	bulbizarre_entry->level = 5;
	bulbizarre_entry->nbown = 1;
	bulbizarre_entry->discover = current_time;
	bulbizarre_entry->capture = current_time;
	bulbizarre_entry->next = NULL;

	printf("\n");
	printf("Vous avez choisi %s ! \n", bulbizarre_entry->nom); 

	pokedex = bulbizarre_entry;
    pokedex->next = NULL;
    return bulbizarre_entry;
}
pokemon *carapuce(void){

	char* current_time = get_date();

	pokemon* carapuce_entry = malloc(sizeof(pokemon));
	carapuce_entry->nom = "Carapuce";
	carapuce_entry->type = "Eau";
	carapuce_entry->level = 5;
	carapuce_entry->nbown= 1;
	carapuce_entry->discover = current_time;
	carapuce_entry->capture = current_time;
	carapuce_entry->next = NULL;

	printf("\n");
	printf("Vous avez choisi %s ! \n", carapuce_entry->nom); 

	pokedex = carapuce_entry;
    pokedex->next = NULL;
    return carapuce_entry;

}

pokemon *salameche(void){

	char* current_time = get_date();

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
    
    
    return salameche_entry;

}
pokemon *start_menu(void){


	int i = 0;

	printf("\n");
	printf("#---Bienvenue jeune dresseur !---#\nAvant de commencer l'aventure tu dois choisir ton premier Pokemon !\n");
	printf("Tu dois choisir parmis ces 3 pokemon\n");
	printf("\n");
	printf("Bulbizarre : 0\n");
	printf("Carapuce : 1\n");
	printf("Salameche : 2\n");
	printf("\n");
	printf("Quel est ton choix : ");

	scanf("%d", &i);

	pokemon * (*array_fptr[3])(void);
	array_fptr[0] = &bulbizarre;
	array_fptr[1] = &carapuce;
	array_fptr[2] = &salameche;

	pokemon *L = array_fptr[i]();

    
    
    return L;
	
}


void print_menu(pokemon* L){
    
	int i = 0; 

	printf("\n");
	printf("/*----------------------------------------------------------------------*/\n");
	printf("\n");
	printf("Afficher tous le Pokedex : 0\n");
	printf("Afficher les informations d'un pokemon : 1\n");
	printf("Retour : 2\n");

	scanf("%d", &i);

	void (*array_fptr[2])(pokemon* );
	array_fptr[0] = &printList;
	// array_fptr[1] = &print_specific_pokemon;
	array_fptr[1] = &pokedex_menu;	

	array_fptr[i](L);	
	
}

pokemon *Read_csv(void){


    FILE *myfile = fopen("pokedex.csv", "r");
    
    pokemon *new_pokemon = NULL;
    pokemon *tmp_starter = NULL;
    pokemon *tmp_pokemon = NULL;
    
    
    
    char *ligne = NULL;
	size_t cpt = 0;

	getline(&ligne, &cpt, myfile);
	free(ligne);
	ligne = NULL;
	cpt = 0;
    int ini = 0;
    
    // char* current_time = get_date();
	 



    if(ini !=0){
            
            pokeadd(new_pokemon, new_pokemon->nom, new_pokemon->type, new_pokemon->level, new_pokemon->nbown, new_pokemon->discover, new_pokemon->capture);
        }   
    else{

            // pokemon* salameche_entry = malloc(sizeof(pokemon));
            // salameche_entry->nom = "Salameche";
            // salameche_entry->type = "Feu";
            // salameche_entry->level = 5;
            // salameche_entry->nbown = 1;
            // salameche_entry->discover = current_time ;
            // salameche_entry->capture = current_time ;
            // salameche_entry->next = NULL;
            // printf("\n");
            // printf("Vous avez choisi %s ! \n", salameche_entry->nom);
            // tmp_starter = salameche_entry;
            int i = 0;
            

            printf("\n");
            printf("#---Bienvenue jeune dresseur !---#\nAvant de commencer l'aventure tu dois choisir ton premier Pokemon !\n");
            printf("Tu dois choisir parmis ces 3 pokemon\n");
            printf("\n");
            printf("Bulbizarre : 0\n");
            printf("Carapuce : 1\n");
            printf("Salameche : 2\n");
            printf("\n");
            printf("Quel est ton choix : ");

            scanf("%d", &i);

            pokemon *(*array_fptr[3])(void);
            array_fptr[0] = &bulbizarre;
            array_fptr[1] = &carapuce;
            array_fptr[2] = &salameche;

            pokemon *L = array_fptr[i]();

            
            tmp_starter = L;
            
            
            
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
        new_node->discover = malloc(sizeof(token)+25);
        strcpy(new_node->discover,token);

        token = strtok(NULL, ";");
        new_node->capture = malloc(sizeof(token)+25);
        strcpy(new_node->capture,token);
        
        
        new_node->next = tmp_starter;
        if (tmp_pokemon != NULL)
        {
            tmp_pokemon->next = new_node;
        }
        
        tmp_pokemon = new_node;
        
        if (new_pokemon == NULL)
        {
            new_pokemon = tmp_pokemon ;
        }
        
        // else
        // {
            
        //     new_pokemon->next = tmp_pokemon;
        // }
        
        free(ligne);
		ligne = NULL;
		cpt = 0;
        
    }
    
    if (tmp_pokemon == NULL)
    { 
        new_pokemon = tmp_starter;
        
    }
    
    
    fclose(myfile);
    return new_pokemon;
}

void adding_pokemon(pokemon *L)
{
    int i = 0;
    char nom[25];
    char type[25];
    int level = 2;
    int nbown = 0;
    char *current_time = get_date();
    char capture [15] = "Pas capturé";

    int nb_index = get_lenght(L);

	printf("\n");
	printf("#---Vous avez trouvé un nouveau pokemon ajouté le à votre pokedex !---#\n");
	printf("\n");
	printf("Souhaitez vous l'attrapper ?\n");
	printf("Oui : 0\n");
	printf("Non : 1\n");

	scanf("%d",&i);

	printf("Saisissez son nom : \n");
	scanf("%s", nom);

	printf("Saisissez son type : \n");
	scanf("%s", type);

	printf("Niveau du pokemon : \n");
	scanf("%d", &level);

	int exist = exist_pokemon(L,nom);

    if(i == 0){

		if(exist == 1 ){

			printf("le pokemon %s\n exist",nom);

			int index_pokemon = get_index(L,nb_index, nom);

			while(L != NULL){

				char* pokemon_pokedex = L->nom;
				
				if(strcmp(nom, pokemon_pokedex) == 0){

					nbown = L->nbown + 1;
					update_element(L,index_pokemon ,L->nbown,nbown,current_time);
						
				}
				
			L = L->next;

			}
		}

		else{	

            nbown = 1 ;
            pokeadd(L, nom, type, level, nbown, current_time, current_time);
		}	
	}

	else if( i == 1){

		nbown = 0 ;
        pokeadd(L, nom, type, level, nbown, current_time, capture);
	}

	else{

		printf("Mauvaise saisie \n");
		adding_pokemon(L);
	}

    
    
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

            void (*array_fptr[5])(pokemon *L);
            array_fptr[0] = &adding_pokemon;
            array_fptr[1] = &print_specific_pokemon;
            array_fptr[2] = &printList;
            array_fptr[3] = &save;
            array_fptr[4] = &quit;
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

void save(pokemon *L){

	pokemon *tmp = L;

	FILE* file = fopen("pokedex.csv", "w");
	
	if(file == NULL){

		fprintf(stderr, "Erreur dans l'ouverture du fichier de sauvegarde\n");
	}

	fprintf(file,"nom;type;level;nbown;discover;capture\n");

	while(tmp != NULL){

		fprintf(file, "%s;%s;%d;%d;%s;%s\n", tmp->nom, tmp->type,tmp->level, tmp->nbown, tmp->discover, tmp->capture);
		tmp = tmp->next;
	
	}

	fclose(file);
}
void quit(pokemon *L){

	int i = 0; 

	printf("Quitter sans sauvegarder : 0\n");
	printf("Quitter et sauvegarder : 1 \n");

	scanf("%d",&i);

	if(i == 0){

		exit(0);
	}

	else if( i == 1){

		save(L);
		exit(0);
	}
}


