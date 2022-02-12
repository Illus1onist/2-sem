#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    if (N % 5 == 0)
        for (int i = 0; i < N; i++)
            cout << '@';
    else
        for (int i = 0; i < N; i++)
            cout << '%';


    return 0;
}