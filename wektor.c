#include <stdlib.h>
#include <stdio.h>
#include "wektor.h"

#define MAXSIZE 2

wektor *make_wektor(){
	wektor *w = malloc (sizeof *w);
	w->linie = malloc (MAXSIZE * sizeof w->linie); 
	w->max=0;
	w->size=MAXSIZE;
	return w;
}

void dodaj_linie (wektor *w,int linia){

	if(w->size+1 > w->max){
		w->max+=MAXSIZE;
		w->linie=realloc(w->linie, w->max * sizeof w->linie);
	}

	w->size++;
	w->linie[w->size]=linia;
	
}	
	
