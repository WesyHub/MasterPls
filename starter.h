#ifndef __STARTER__
#define __STARTER__


pokemon *Read_csv(void);
void pokedex_menu(pokemon *L);
char* get_date(void);
pokemon *init(char *nom, char *type,int level, int nbown, char * discover, char * capture);

#endif /*  __STARTER__ */