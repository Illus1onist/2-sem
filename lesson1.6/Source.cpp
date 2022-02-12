#include <iostream>

using namespace std;

int main()
{
    int N, a,b, count = 0, max = 0;
    cin >> N;
    cin >> a;
    while (N - 1 > 0)
    {
        cin >> b;
        if (b >= a)
            count = count + 1;
        else
            count = 0;
        if (count > max)
            max = count;
        N = N - 1;
        a = b;
    }

    cout << max+1;
    return 0;
}