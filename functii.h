#ifndef functii
#define functii

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

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
    cout << strspn(a,b) << endl;
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

#endif
