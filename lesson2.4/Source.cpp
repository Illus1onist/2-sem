#include <iostream>
#include <cstdio>
using namespace std;
//press '1' and 'enter' to get one number. You can do it many times
//press '0' to reset
long long int nextprime();
bool isprime(long long int x);

long long int nextprime(int h) {
    static long long int a = 1;
    if (h == 0)
        a = 1;
    a = a + 1;
    int k = 0;
    while (k == 0)
        if (isprime(a) == false)
            a = a + 1;
        else
            k = 1;
    return(a);
    
}



bool isprime(long long int x) {
    bool s;
    int k = 0;
    for (int i = 2; i <= std::sqrt(x); i++)
        if (x % i == 0) {
            k = k + 1;
            break;
        }
    if (k == 0 && x != 1)
        s = true;
    else
        s = false;
    return(s);
}

int main()
{
    int a = 0;
    while (cin >> a && (a==1 || a==0))
            cout << nextprime(a) << endl;
    return 0;
}