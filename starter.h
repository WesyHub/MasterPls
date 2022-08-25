#ifndef __STARTER__
#define __STARTER__


pokemon *Read_csv(void);
void pokedex_menu(pokemon *L);
char* get_date(void);
pokemon *init(char *nom, char *type,int level, int nbown, char * discover, char * capture);
pokemon *salameche(void);
pokemon *carapuce(void);
pokemon *bulbizarre(void);
void print_menu(pokemon* L);
pokemon *start_menu(void);
void save(pokemon *L);
void quit(pokemon *L);
void delete_pokemon(pokemon *L);
char *verif(void);
#endif /*  __STARTER__ */