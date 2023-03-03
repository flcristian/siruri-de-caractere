#ifndef EXERCITII-SET-2_H_INCLUDED
#define EXERCITII-SET-2_H_INCLUDED

#include "functii-set-2.h"

using namespace std;

/// Problema 1
/// Se citeste un sir de maxim 200 de caractere, cuvinte separate prin unul
/// sau mai multe spatii.
/// a) Sa se eliminte spatiile dintre cuvinte.
/// b) Sa se transforme prima litera din fiecare cuvant in litera
/// mare si sa se inlocuiasca ultima litera din fiecare cuvant cu urmatoarea de
/// dupa ea din alfabet.
/// c) Dublati toate vocalele mari si stergeti toate vocalele mici.
/// d) Realizati suma tuturor cifrelor din sir.
/// e) Realizati media aritmetica a tuturor codurilor ASCII la caracterele de tip
/// litera mica.
/// f) Sa se verifice de cate ori apare ultimul cuvant in tot sirul.
/// g) Interschimbati elementele sirului in oglinda fata de mijloc.
/// h) Cate litere mici avem? Sunt toate litere consoane?

void rezolvareProblema1a(char s[200]){
    char sir[200]="";
    strcpy(sir, s);
    removeSpatiu(sir);
    cout << "a) " << sir << endl;
}

void rezolvareProblema1b(char s[200]){
    char sir[200]="";
    strcpy(sir,s);
    primaLiteraMare(sir);
    ultimaLiteraPlus1(sir);
    cout << "b) " << sir << endl;
}

void rezolvareProblema1c(char s[200]){
    char sir[200]="";
    strcpy(sir,s);
    doubleVocaleMari(sir);
    removeVocaleMici(sir);
    cout << "c) " << sir << endl;
}

void rezolvareProblema1d(char s[200]){
    int suma = 0;
    for(int i = 0;i<strlen(s);i++){
        char x[3]="";
        x[0]=s[i];
        suma += atoi(x);
    }
    cout << "d) " << suma << endl;
}

void rezolvareProblema1e(char s[200]){
    int nr = 0;
    int suma = 0;
    for(int i = 0;i<strlen(s);i++){
        if(s[i]>=97 && s[i]<=122){
            suma += s[i];
            nr++;
        }
    }
    double medie = suma/nr;
    cout << "e) " << medie << endl;
}

void rezolvareProblema1f(char s[200]){
    char cuvant[200]="", sir[200];
    ultimulCuvant(s, cuvant);
    strcpy(sir, s);
    int ct;
    countCuvantSir(sir, cuvant, ct);
    cout << "f) " << ct << endl;
}

void rezolvareProblema1g(char s[200]){
    char sir[200]="";
    int countCuvinte;
    totalCuvinteSir(s, countCuvinte);
    if(countCuvinte%2==0){
        oglindaPare(sir, countCuvinte);
    }
   // else{
     //   oglindaImpare(sir, countCuvinte);
    //}
    cout << "g) " << sir << endl;
}

void problema1(){
    char s[200]="";
    cout << "Introduceti sirul : ";
    cin.getline(s,200);
    rezolvareProblema1a(s);
    rezolvareProblema1b(s);
    rezolvareProblema1c(s);
    rezolvareProblema1d(s);
    rezolvareProblema1e(s);
    rezolvareProblema1f(s);
    rezolvareProblema1g(s);
}

#endif
