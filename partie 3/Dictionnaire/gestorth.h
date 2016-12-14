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
void correctTxt(part3* p2);

#endif /* GESTORTH_H */

