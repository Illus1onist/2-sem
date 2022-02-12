#include <iostream>
#include <cstdio>
using namespace std;

void makenice() {
    char c;
    long int a = 0;
    while (cin >> c && c != '@')
        if (c >= '0' && c <= '9')
            a = 10 * a + c - '0';
    cout << a;

}

int main()
{
    makenice();

    return 0;
}