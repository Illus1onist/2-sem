#include <iostream>

using namespace std;

int main()
{
    int N, x, min;
    cin >> N;
    cin >> min;
    while (N-1 > 0)
    {
        cin >> x;
        N = N - 1;
        if (x < min) 
            min = x;
    }
        
    cout << min;
    return 0;
}