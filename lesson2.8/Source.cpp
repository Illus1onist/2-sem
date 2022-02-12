#include <iostream>
#include <cstdio>
using namespace std;

long long int fromSixteenToTen(string s) {
    char c;
    string f = s;
    long long int a = 0;
    int b = 0;
    for (int i = 0; i < f.length(); i++)
    {
        c = f[i];
        if (f[i]-'0'>=0 && f[i]-'0'<=9)
            b = c - '0';
        if (f[i] - 'A' >= 0 && f[i] - 'A' <= 5)
            b = 10 + f[i] - 'A';
        a = a * 16 + b;
    }
    return(a);
}

int main()
{
    string a,b;
    cin >> a;
    cin >> b;
    cout<< fromSixteenToTen(a)+ fromSixteenToTen(b);

    return 0;
}