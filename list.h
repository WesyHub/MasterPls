#ifndef __LIST__
#define __LIST__

typedef struct pokemon_t{
    char * nom;
    char * type;
    int level;
    int nbown;
    char * discover;
    char * capture;
    struct pokemon_t *next;
    struct pokemon_t *prev;
    struct pokemon_t *first;

}pokemon;

void printList(pokemon *L);
void pokeadd(pokemon *L, char *nom, char *type, int level, int nbown, char *discover, char *capture);
int get_lenght(pokemon * L);
int get_index(pokemon *L, int lenght, char * pokemon_search);
void update_element(pokemon *L, int index , int old_value, int new_value, char* capture);
int exist_pokemon(pokemon *L, char *nom);
void print_specific_pokemon(pokemon *L);
#endif /*__LINKED_LIST__ */