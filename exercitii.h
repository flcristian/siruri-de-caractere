#ifndef EXERCITII_H_INCLUDED
#define EXERCITII_H_INCLUDED

#include "functii.h"

using namespace std;

// Problema 1

void problema1(){
    char text[255]="", litera[100]="", silaba[100]="";
    cout << "Introduceti textul : ";
    cin.getline(text, 255);
    cout << "Introduceti litera : ";
    cin.getline(litera, 100);
    cout << "Introduceti silaba : ";
    cin.getline(silaba, 100);
    _strlwr(text);
    cout << "a) " << numarLitera(text, litera[0]) << endl;
    cout << "b) " << numarVocale(text) << endl;
    cout << "c) " << numarSilabe(text, silaba) << endl;
}

// Problema 2

void problema2(){
    char cuvant[100]="", litera[100]="";
    cout << "Introduceti cuvantul : ";
    cin.getline(cuvant, 100);
    cout << "Introduceti litera : ";
    cin.getline(litera, 100);
    stergereLitera(cuvant, litera);
    cout << "Rezultatul este : " << cuvant << endl;
}

// Problema 3

void rezolvareProblema3(char* text){
    while(strlen(text) > 2){
        stergerePozitie(text, 0);
        stergerePozitie(text, strlen(text) - 1);
        cout << text << endl;
    }
}

void problema3(){
    char cuvant[100]="";
    cout << "Introduceti cuvantul : ";
    cin.getline(cuvant, 100);
    rezolvareProblema3(cuvant);
}

// Problema 4

void problema4(){
    char x[1000][1000], nr[10];
    int n;
    cout << "Introduceti numarul de linii : ";
    cin.getline(nr, 10);
    n = atoi(nr);
    for(int i = 0;i<n;i++){
        cout << "Introduceti textul de pe linia " << i + 1 << " : ";
        cin.getline(x[i], 1000);
    }
    cout << "Lungimea maxima a unei propozitii din matrice este : " << maxLenghtMatrice(x, n) << endl;
}

// Problema 5

void problema5(){
    char cuvant[100]="";
    cout << "Introduceti cuvantul : ";
    cin.getline(cuvant, 100);
    swapUprLwr(cuvant);
    cout << cuvant << endl;
}

// Problema 6

void rezolvareProblema6(char x[1000][1000], int n){
    int m = 0, istanga = 0, idreapta = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i != j){
                int s = strlen(x[i]) + strlen(x[j]);
                if(s > m){
                    m = s;
                    istanga = i, idreapta = j;
                }
            }
        }
    }
    cout << x[istanga] << x[idreapta] << endl;
}

void problema6(){
    char x[1000][1000], nr[10]="";
    cout << "Introduceti numarul de cuvinte : ";
    cin.getline(nr, 10);
    int n = atoi(nr);
    for(int i = 0;i<n;i++){
        cout << "Introduceti cuvantul " << i + 1 << " : ";
        cin.getline(x[i], 1000);
    }
    rezolvareProblema6(x, n);
}

// Problema 7

// ? ? ?

#endif
