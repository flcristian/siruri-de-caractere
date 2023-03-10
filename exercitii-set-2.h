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
    strcpy(sir, s);
    oglindaMijloc(sir);
    cout << "g) " << sir << endl;
}

void rezolvareProblema1h(char s[200]){
    char sir[200]="";
    strcpy(sir, s);
    int ct = cateLitereMici(s);
    cout << "h) " << ct << " + ";
    if(suntToateLitereleConsoane(s)){
        cout << "da" << endl;
    }
    else{
        cout << "nu" << endl;
    }
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
    rezolvareProblema1h(s);
}

/// Problema 2
/// Se citeste un sir de maxim 200 de caractere,
/// cuvinte separate prin separatorii " ,.!?;:".
/// a) Realizati un nou sir cu toate cuvintele palindrome.
/// b) Afisati cuvantul ce are cele mai multe vocale.
/// c) Modificati sirul citit astfel incat sa stergeti
/// toate cuvintele ce au mai putin de 4 caractere.
/// d) Care este al treilea cuvant citit? Daca sirul nu are
/// cel putin 3 cuvinte se va afisa un mesaj.
/// e) Stergeti cuvintele de exact 5 litere ce au prima si
/// ultima litera identice.
/// f) Dublati grupurile de 3 litere identice.
/// g) Transformati ultima litera din fiecare cuvant (doar daca
/// este litera mica) in litera mare.
/// h) Sa se afiseze toate cuvintele din sir ce au prefix pe
/// primul cuvant al textului.

void rezolvareProblema2a(char cuvinte[200][200], int d){
    int ct = 0;
    char sir[10000]="";
    char spatiu[3]=" ";
    for(int i = 0;i<d;i++){
        char invers[200]="";
        inversCuvant(invers, cuvinte[i]);
        if(strcmp(invers, cuvinte[i])==0){
            strcat(sir, cuvinte[i]);
            strcat(sir, spatiu);
            ct++;
        }
    }
    cout << "a) ";
    if(ct > 0){
        cout << sir;
    } else{
        cout << "nu exista";
    }
    cout << endl;
}

void rezolvareProblema2b(char cuvinte[200][200], int d){
    int max = 0, r = 0;
    for(int i = 0;i<d;i++){
        int ct = countVocale(cuvinte[i]);
        if(ct>max){
            max = ct;
            r = i;
        }
    }
    cout << "b) " << cuvinte[r] << endl;
}

void rezolvareProblema2c(char cuvinte[200][200], int d){
    char sir[10000]="";
    char spatiu[3]=" ";
    for(int i = 0;i<d;i++){
        if(strlen(cuvinte[i])>3){
            strcat(sir, cuvinte[i]);
            strcat(sir, spatiu);
        }
    }
    cout << "c) " << sir << endl;
}

void rezolvareProblema2d(char cuvinte[200][200], int d){
    cout << "d) ";
    if(d > 2){
        cout << cuvinte[2];
    }
    else{
        cout << "nu exista";
    }
    cout << endl;
}

void rezolvareProblema2e(char cuvinte[200][200], int d){
    int ct = 0;
    char sir[10000]="";
    char spatiu[3]=" ";
    for(int i = 0;i<d;i++){
        if(strlen(cuvinte[i]) == 5 && (cuvinte[i][0] == cuvinte[i][strlen(cuvinte[i]) - 1])){
            ct++;
        }
        else{
            strcat(sir, cuvinte[i]);
            strcat(sir, spatiu);
        }
    }
    cout << "e) ";
    if(ct < d){
        cout << sir;
    }
    else{
        cout << "toate cuvintele au aceste proprietati";
    }
    cout << endl;
}

void rezolvareProblema2f(char s[200]){
    char sir[200]="";
    strcpy(sir, s);
    dublareGrupuri3(sir);
    cout << "f) " << sir << endl;
}

void rezolvareProblema2g(char cuvinte[200][200], int d){
    char sir[200]="";
    char spatiu[3]=" ";
    for(int i = 0;i<d;i++){
        char cuvant[200]="";
        strcpy(cuvant, cuvinte[i]);
        int j = strlen(cuvant) - 1;
        char a = cuvant[j];
        if(a >= 97 && a <= 122){
            cuvant[j] = cuvant[j] - 32;
        }
        strcat(sir, cuvant);
        strcat(sir, spatiu);
    }
    cout << "g) " << sir << endl;
}

void rezolvareProblema2h(char cuvinte[200][200], int d){
    char r[200]="";
    strcpy(r, cuvinte[d-1]);
    cout << "h) ";
    for(int i = 0;i<d-1;i++){
        if(strstr(cuvinte[i], r) == cuvinte[i]){
            cout << cuvinte[i] << " ";
        }
    }
}

void problema2(){
    char s[200]="";
    cout << "Introduceti sirul : ";
    cin.getline(s,200);
    char cuvinte[200][200];
    int d;
    separareCuvinte(s, cuvinte, d);
    rezolvareProblema2a(cuvinte, d);
    rezolvareProblema2b(cuvinte, d);
    rezolvareProblema2c(cuvinte, d);
    rezolvareProblema2d(cuvinte, d);
    rezolvareProblema2e(cuvinte, d);
    rezolvareProblema2f(s);
    rezolvareProblema2g(cuvinte, d);
    rezolvareProblema2h(cuvinte, d);
}

#endif
