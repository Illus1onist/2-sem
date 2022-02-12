#include <iostream>
#include <cstdio>
using namespace std;

//кто-то сказал, что без функции будет быстрее и круче. Я верю.
int main()
{
    int a;
    long long int b = 1,c = 1;
    cin >> a;
    if (a < 3)
        c = 1;
    if (a >= 3)
        for (int i = 0; i < a-2; i++)
        {
            c = c + b;
            b = c - b;
        }
    cout << c;
    return 0;
}