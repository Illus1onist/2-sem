#include <iostream>
#include <cstdio>
using namespace std;

void binary(long long int a) {
    int b = a % 2;
    if (a / 2 != 0)
        binary(a / 2);
    cout << b;

}

int main()
{
    long int a;
    cin >> a;
    binary(a);

    return 0;
}