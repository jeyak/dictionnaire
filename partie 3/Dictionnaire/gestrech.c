/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gestrech.c
 * Author: rjeya
 *
 * Created on 13 décembre 2016, 09:23
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Retourne les differences entre deux char* (chaine de caractere)
 */
unsigned int strDiff(char *str1Input, char *str2Input){
    //printf("%s", str1Input);
    // printf("%s", str2Input);

    unsigned int charDiff = 0;
    int i = 0;
    int exit = 0; // Variable servant a sortir de la bloucle
    while(exit == 0){
        if(str1Input[i] != str2Input[i]){
            charDiff++; // On incremente a chaque fois que qu'on tombe sur un caractère different
        }
        i++;
        if(str1Input[i] == '\0' || str2Input[i] == '\0')
        {
            // Ajout des caractère supplémentaire du plus string
            charDiff += (strlen(str1Input) > strlen(str2Input) ? strlen(str1Input) - strlen(str2Input) : strlen(str2Input) - strlen(str1Input));
            exit = 1;
        }
    }
    return charDiff;
}

