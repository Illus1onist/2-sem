#include <iostream>
#include <cassert>
using namespace std;

bool isprime(long long int x) {
    bool s;
    int k=0;
    for (int i = 2; i <= std::sqrt(x); i++)
        if (x % i == 0) {
            k = k+1;
            break;
        }
    if (k == 0 && x!=1)
        s = true;
    else
        s = false;
    return(s);
}

int main()
{
    assert(isprime(5) == 1);
    assert(isprime(1) == 0);
    assert(isprime(991) == 1);
    long long int x;
    bool a;
    std::cin >> x;
    a = isprime(x);
    cout << a;
    return 0;
}