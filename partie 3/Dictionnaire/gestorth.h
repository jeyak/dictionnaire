#ifndef GESTORTH_H
#define GESTORTH_H

typedef struct part3{
    char wordTxt[50];
    char wordDico[50];
    FILE* fTxt;
    FILE* fDico;
    int resSearch;
}part3;

void afficheNotFound(int tp);
void afficheAndWordProche(part3* p1, int tp);
unsigned int correctTxt(part3* p2, FILE* newTxt);

#endif /* GESTORTH_H */

