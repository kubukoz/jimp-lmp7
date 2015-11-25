#include <string.h>
#include "szukaj.h"

int szukaj(char *buf, char *klucz){

    int n=0;
    char *wsk=buf;
    
    wsk=strstr(buf,klucz);
    
    while(wsk!=NULL){
        wsk--;
/* Nie wiem czemu ale jak to dodałem to działa dla przypadku jak słowo jest na początku oO */
        if((*wsk==' ')||(*wsk=='\0')){
            wsk+= 1+strlen(klucz);
            if((*wsk==' ')||(*wsk=='\0'))
                n++;
        }
        wsk=strstr(wsk+2,klucz);
    }
    
    printf("%d\n",n);
    return n;
}

