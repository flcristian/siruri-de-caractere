#ifndef FUNCTII-SET-2_H_INCLUDED
#define FUNCTII-SET-2_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

void removePozitie(char s[200], int i){
    char text[200]="";
    strncpy(text, s, i);
    strcat(text, s+i+1);
    strcpy(s, text);
}

void removeSpatiu(char s[200]){
    for(int i = 0; i<strlen(s);i++){
        if(s[i] == ' '){
            removePozitie(s, i);
            i--;
        }
    }
}

void primaLiteraMare(char s[200]){
    for(int i = 0;i<strlen(s);i++){
        if(s[i-1] == NULL || s[i-1] == ' '){
            if(s[i]>=97 && s[i]<=122){
                s[i]-=32;
            }
        }
    }
}

void ultimaLiteraPlus1(char s[200]){
    for(int i = 0;i<strlen(s);i++){
        if(s[i+1] == NULL || s[i+1] == ' '){
            if(s[i] != 'z' && s[i] != 'Z'){
                s[i]++;
            }
        }
    }
}

bool esteVocalaMica(char x){
    char vocale[5]={'a','e','i','o','u'};
    for(int i = 0;i<5;i++){
        if(x == vocale[i]){
            return 1;
        }
    }
    return 0;
}

bool esteVocalaMare(char x){
    char vocale[5]={'A','E','I','O','U'};
    for(int i = 0;i<5;i++){
        if(x == vocale[i]){
            return 1;
        }
    }
    return 0;
}

void addCaracterPozitie(char s[200], int i, char x){

    int dim=strlen(s);
    for(int j = strlen(s);j>i;j--){
        s[j] = s[j-1];
    }
    s[i] = x;

    s[dim+1]='\0';
}

void doubleVocaleMari(char s[200]){
    for(int i = 0;i<strlen(s);i++){
        if(esteVocalaMare(s[i])){
            addCaracterPozitie(s,i+1,s[i]);
            i++;
        }
    }
}

void removeVocaleMici(char s[200]){
    for(int i = 0;i<strlen(s);i++){
        if(esteVocalaMica(s[i])){
            removePozitie(s, i);
        }
    }
}

void ultimulCuvant(char s[200], char cuvant[200]){
    int i = strlen(s) - 1;
    while(s[i]!=' ' && s[i]!=NULL){
        i--;
    }
    strcat(cuvant, s+i+1);
}

void countCuvantSir(char sir[200], char cuvant[200], int& ct){
    ct = 0;
    char *temp=strstr(sir, cuvant);
    while(temp!=NULL){
        ct++;
        strcpy(sir,temp+strlen(cuvant));
        temp=strstr(sir,cuvant);
    }
}

void totalCuvinteSir(char s[200], int& countCuvinte){
    int countSpatii = 0;
    for(int i = 0;i<strlen(s);i++){
        if(s[i]==' '){
            countSpatii++;
        }
    }
    countCuvinte = countSpatii + 1;
}

void oglindaPare(char s[200], int countCuvinte){
    int countSpatii = 0, i = 0;
    while(countSpatii < countCuvinte / 2){
        if(s[i]==' '){
            countSpatii++;
        }
        i++;
    }
    char seg1[200]="";
    strncpy(seg1, s, i);
    cout << seg1 << endl;
}

#endif
