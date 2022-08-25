#ifndef __SIGNAL__
#define __SIGNAL__

#include <stddef.h>
#include <stdio.h>
#include <signal.h>

/* Prototype */ 


void quit_signal(int sig);
void save_auto(int sig);
#endif /* __SIGNAL__ */