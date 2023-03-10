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

void oglindaMijloc(char s[200]){
    for(int i = 0, j = strlen(s) - 1; i < strlen(s)/2;i++,j--){
        char r = s[i];
        s[i]=s[j];
        s[j]=r;
    }
}

bool esteVocala(char x){
    char vocale[10]={'a','e','i','o','u','A','E','I','O','U'};
    for(int i = 0;i<10;i++){
        if(x == vocale[i]){
            return 1;
        }
    }
    return 0;
}

int cateLitereMici(char s[200]){
    int count = 0;
    for(int i = 0;i<strlen(s);i++){
        if(s[i]>=97 && s[i]<=122){
            count++;
        }
    }
    return count;
}

bool suntToateLitereleConsoane(char s[200]){
    for(int i = 0;i<strlen(s);i++){
        if((s[i]>=65&&s[i]<=90) || (s[i]>=97 && s[i]<=122)){
            if(esteVocala(s[i])){
                return 0;
            }
        }
    }
    return 1;
}

void separareCuvinte(char s[200], char cuvinte[200][200], int& d){
    char sir[200]="";
    strcpy(sir, s);
    d = 0;
    char* a;
    a = strtok(sir, " ");
    while(a != NULL){
        strcpy(cuvinte[d], a);
        d++;
        a = strtok(NULL, " ");
    }
}

void inversCuvant(char cuvant[200]){
    char invers[200]="";
    char a[3]="";
    for(int i = strlen(cuvant); i>-1;i--){
        a[0]=cuvant[i];
        strcat(invers, a);
    }
    strcpy(cuvant, invers);
}

bool estePalindrom(char cuvant[200]){
    char invers[200]="";
    strcpy(invers, cuvant);
    inversCuvant(invers);
    if(strcmp(cuvant, invers)==0){
        return 1;
    }
    return 0;
}

int countVocale(char s[200]){
    int ct = 0;
    for(int i = 0;i<strlen(s);i++){
        if(esteVocala(s[i])){
            ct++;
        }
    }
    return ct;
}

bool conditie(char s[5]){
    for(int i = 0;i<2;i++){
        if(s[i] != s[i+1]){
            return 0;
        }
    }
    return 1;
}

void dublareGrupuri3(char s[200]){
    char seg[5]="";
    for(int i = 0;i<strlen(s);i++){
        strncpy(seg, s+i, 3);
        if(conditie(seg)){
            char text[200]="";
            strncpy(text, s, i+3);
            strcat(text, seg);
            strcat(text, s+i+3);
            strcpy(s, text);
            i = i + 5;
        }
    }
}

void ultimaLiteraPlus1v2(char cuvant[200]){
    int i = strlen(cuvant) - 1;
    if((cuvant[i]>=65 && cuvant[i]<=89) || (cuvant[i]>=97 && cuvant[i]<=121)){
        cuvant[i]++;
    }
}

struct CuvantF{
    char cuvant[200]="";
    int id;
    int frecventa = 1;
};

int getPosition(CuvantF cuvinte[200], int d, char cuvant[200]){
    for(int i = 0;i<d;i++){
        if(strcmp(cuvinte[i].cuvant, cuvant) == 0){
            return i;
        }
    }
    return -1;
}

void frecventaCuvinteSir(char s[10000], CuvantF cuvinte[200], int& d){
    char sir[200]="";
    strcpy(sir, s);
    d = 0;
    char* a;
    a = strtok(s, " ");
    while(a != NULL){
        char cuvant[200]="";
        strcpy(cuvant, a);
        int pos = getPosition(cuvinte, d, cuvant);
        if(pos == -1){
            strcpy(cuvinte[d].cuvant, cuvant);
            cuvinte[d].id = d;
            d++;
        } else {
            cuvinte[pos].frecventa++;
        }
        a = strtok(NULL, " ");
    }
}

bool esteC(char a){
    if(a == 'C' || a == 'c'){
        return 1;
    }
    return 0;
}

bool esteD(char a){
    if(a == 'D' || a == 'd'){
        return 1;
    }
    return 0;
}

void minusCdoubleD(char s[10000]){
    for(int i = 0;i<strlen(s);i++){
        if(esteC(s[i])){
            removePozitie(s, i);
        }
        else if (esteD(s[i])){
            addCaracterPozitie(s, i, s[i]);
            i++;
        }
    }
}

#endif
