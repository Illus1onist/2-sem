#include <iostream>
#include <cstdio>
using namespace std;

bool check(string s) {
    bool f = true;
    long int a=0, b=0, c=0, d=0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '<')
            a = a + 1;
        if (s[i] == '{')
            b = b + 1;
        if (s[i] == '[')
            c = c + 1;
        if (s[i] == '(')
            d = d + 1;
        if (s[i] == '>')
            a = a - 1;
        if (s[i] == '}')
            b = b - 1;
        if (s[i] == ']')
            c = c - 1;
        if (s[i] == ')')
            d = d - 1;

        if (a < 0 || b < 0 || c < 0 || d < 0)
            {
            f = false;
            break;
            }   
    }
    return(f);
}

int main()
{
    string a;
    cin >> a;
    if (check(a))
        cout << "Everything is OK";
    else
        cout << "Vi razozlili partiyu!- 15 ochkov socialnogo reitinga";
    return 0;
}