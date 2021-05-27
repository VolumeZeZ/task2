
#include <string.h>
#include <iostream>
#include <locale.h>
#include<cstring>
#include <cctype>
#include <Class.h>

using namespace std;


int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    int menu = 0;
    StringId* a = new StringId;
    *a >> cin;
    *a << cout;
    a->lenght();
    a->uppercase();
    return 0;
}

