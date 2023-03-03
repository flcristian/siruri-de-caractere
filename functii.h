#ifndef functii
#define functii

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Teste

void test(){
    char sir[100]="";
    cin.getline(sir, 100);
    cout << sir << endl;
    char*s=sir;

    cout<<s;
}

void testStrlen(){
    char s[100]="";
    cin.getline(s,100);
    int n = strlen(s);

    cout << n << endl;
}

void testStrcpy(){
    char s[100]="", x[100]="";
    cin.getline(s,100);
    strcpy(x, s);

    cout << x;
}

void testStrcat(){
    char s[100]="", x[100]="";
    cin.getline(s, 100);
    cin.getline(x,100);
    strcat(x,s);

    cout << x << endl;
}

void testStrncat(){
    char s[100]="", x[100]="";
    cin.getline(s, 100);
    cin.getline(x,100);
    strncat(x,s, 4);

    cout << x << endl;
}

void testStrchr(){
    char s[100]="";
    cin.getline(s,100);
    cout << strchr(s,'a') << endl;
    cout << strrchr(s, 'b') << endl;
}

void testStrcmp(){
    char a[100]="",b[100]="";
    cin.getline(a,100);
    cin.getline(b,100);
    cout << strcmp(a,b);
    cout << stricmp(a, b); // Nu face diferenta intre litere mari sau mici.
}

void testStrstr(){
    char a[100]="",b[100]="";
    cin.getline(a,100);
    cin.getline(b,100);
    cout << strstr(a,b) << endl;
}

void testStrlwrAndStrupr(){
    char s[100]="";
    cin.getline(s,100);
    _strlwr(s);
    cout << s << endl;
    _strupr(s);
    cout << s << endl;
}

void testStrpbrk(){
    char a[100]="",b[100]="";
    cin.getline(a,100);
    cin.getline(b,100);
    cout << strpbrk(a,b);
}

void testStrtok(){
    char a[100]="",b[100]="";
    cin.getline(a,100);
    cin.getline(b,100);
    cout << strtok(a,b);
}

void testStrspn(){
    char a[100]="",b[100]="";
    cin.getline(a,100);
    cin.getline(b,100);
    cout << strspn(a, b) << endl;
    cout << strcspn(a, b) << endl;
}

void testConvert(){
    char s[100]="";
    cin.getline(s,100);
    cout << atof(s) << endl;
    cout << atoi(s) << endl;
    itoa(123, s, 10);
    cout << s;
}

// Functii

int numarLitera(char* text, char litera){
    int countlitera = 0;
    for(int i = 0; i<strlen(text);i++){
        if(text[i] == litera){
            countlitera++;
        }
    }
    return countlitera;
}

int numarVocale(char* text){
    char vocale[5]={'a','e','i','o','u'};
    int countvocale = 0;
    for(int i = 0;i < 5;i++){
        for(int j = 0;j<strlen(text);j++){
            if(text[j] == vocale[i]){
                countvocale++;
            }
        }
    }
    return countvocale;
}

int numarSilabe(char* text, char* silaba){
    int countsilaba=0;
    char *temp=strstr(text,silaba);
    while(temp!=NULL){
        countsilaba++;
        strcpy(text,temp+strlen(silaba));
        temp=strstr(text,silaba);
    }
    return countsilaba;
}

void stergerePozitie(char* text, int i){
    char seg1[100]="";
    strncpy(seg1, text, i);
    strcat(seg1, text+i+1);
    strcpy(text, seg1);
}

void stergereLitera(char* text, char* litera){
    for(int i = 0;i<strlen(text);i++){
        if(text[i] == litera[0]){
            stergerePozitie(text, i);
        }
    }
}

int maxLenghtMatrice(char x[1000][1000], int n){
    int m = 0;
    for(int i = 0;i<n;i++){
        if(strlen(x[i]) > m){
            m = strlen(x[i]);
        }
    }
    return m;
}

void swapUprLwr(char* cuvant){
    for(int i = 0;i<strlen(cuvant);i++){
        if(cuvant[i]>90){
            cuvant[i] = cuvant[i] - 32;
        } else{
            cuvant[i] = cuvant[i] + 32;
        }
    }
}

void addPb7(char s[2][1000], char solutii[1000][1000], int& nrsolutii){
    char x[1000]="";
    strcat(x, s[0]);
    strcat(x, s[1]);
    strcpy(solutii[nrsolutii], x);
    nrsolutii++;
}

bool validPb7(char s[2][1000], int k){
    for(int i = 0;i<k;i++){
        if(strcmp(s[i], s[i+1]) >= 0){
            return 0;
        }
    }
    return 1;
}

bool solutiePb7(int k){
    if(k == 1){
        return 1;
    }
    return 0;
}

void backPb7(char x[1000][1000], char s[2][1000], char solutii[1000][1000], int n, int& nrsolutii, int k){
    for(int i = 0;i<n;i++){
        strcpy(s[k], x[i]);
        if(validPb7(s, k)){
            if(solutiePb7(k)){
                addPb7(s, solutii, nrsolutii);
            } else{
                backPb7(x,s,solutii,n,nrsolutii,k+1);
            }
        }
    }
}

void sortPb7(char solutii[1000][1000], int nrsolutii){
    bool flag = true;
    do{
        flag = true;
        for(int i = 0;i<nrsolutii-1;i++){
            if(strcmp(solutii[i], solutii[i+1])>0){
                char x[1000]="";
                strcpy(x, solutii[i]);
                strcpy(solutii[i], solutii[i+1]);
                strcpy(solutii[i+1], x);
                flag = false;
            }
        }
    } while(!flag);
}




























#endif
