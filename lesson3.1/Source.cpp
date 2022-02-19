#include <iostream>
#include <cstdio>
#include <random>
#include <time.h>
using namespace std;
mt19937 rnd(time(NULL));
long int const height = 1000, width = 1000;

int main()
{

    //    cout << rnd() << ' ' << rnd() << endl;
    //    uniform_int_distribution<int> distrib(1, 10);
    //    cout << distrib(rnd) << endl;
    long long int d = 0;
    long int it = 1000;
    for (long int f = 0; f < it; f++)
    {
        long long int a = 0, b=0;
        long long int s = 0;
        while (true)
        {
            if (rnd() % 4 == 0)
                a = a + 1;
            if (rnd() % 4 == 1)
                a = a - 1;
            if (rnd() % 4 == 2)
                b = b + 1;
            if (rnd() % 4 == 3)
                b = b - 1;
            s = s + 1;
            if (abs(a)==width/2 || abs(b)==height/2)
                break;
        }
        d = d + s;
    }
    cout<<float(d) / it;
    return 0;
}