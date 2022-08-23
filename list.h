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

#endif /*__LINKED_LIST__ */