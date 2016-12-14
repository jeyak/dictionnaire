/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestorth.h"
#include "gestrech.h"


void afficheNotFound(int tp){ // partie 1 affichage des mots non present

    part3* p = malloc(sizeof(part3));
    p->fTxt = fopen(".\\ressources\\readFile.txt", "r");
    
    char* str = NULL;
    str = fUse();
    if(str == NULL){
        return;
    }
    p->fDico = fopen(str, "r");
    char ch = ' ';
    
    unsigned int i, j, count = 0, index = 0;
    
    if(!fExiste(p->fTxt)) // Si le fichier n'existe pas
    {// Erreur
        printf("Le fichier d'entree n'existe pas !");
        return;
    }
    
    while ((ch = getc ( p->fTxt )) != EOF ) { // parcours tant que pas fin de fichier
        if ( ch != ' '){
            p->wordTxt[index++] = ch; // insere   la suite tant que pas ' '
        }else {
            p->wordTxt[index] = '\0'; // remplace ' ' par un \0 fin de chaine
            index=0;
            Capitalize(p->wordTxt);
            while ((ch = getc ( p->fDico )) != EOF ) { // parcours tant que pas fin de fichier
                if ( ch != '\n'){
                    p->wordDico[index++] = ch; // insere   la suite tant que pas \n
                }else {
                    p->wordDico[index] = '\0'; // remplace \n par un \0 fin de chaine
                    index=0;
                    Capitalize(p->wordTxt);
                    if(strcmp(p->wordTxt, p->wordDico) == 0){
                        count = 1;
                        break;
                    }
                }
            }
            if(count != 1){
                printf("%s\n", p->wordTxt); // demmande de liste de mots non trouvé
                if(tp > 1){
                    afficheAndWordProche(p, tp);
                }
            }
            count = 0;
        }
    }
    free(p);
}

void afficheAndWordProche(part3* p1, int tp){
    char ch = ' ';
    unsigned int index = 0;
    
    rewind(p1->fDico);
    while ((ch = getc ( p1->fDico )) != EOF ) { // parcours tant que pas fin de fichier
        if ( ch != '\n' && ch != ' ' && ch != ',' && ch != '.'){
            p1->wordDico[index++] = ch; // insere   la suite tant que pas \n
        }else {
            p1->wordDico[index] = '\0'; // remplace \n par un \0 fin de chaine
            index=0;
            Capitalize(p1->wordTxt);
            if(tp == 2){
                if((strDiff(p1->wordTxt,p1->wordDico)) <= 2){
                    printf("\t%s\n", p1->wordDico);
                }else{
                    correctTxt(p1);
                }
            }
        }
    }
}


void correctTxt(part3* p2){
    FILE* newTxt = fopen(".\\ressources\\cor.txt", "w");
    if((strDiff(p2->wordTxt, p2->wordDico)) <= 1){
        fprintf(newTxt, "%s ", p2->wordDico);
    }else{
        fprintf(newTxt, "%s ", p2->wordTxt);
    }

}