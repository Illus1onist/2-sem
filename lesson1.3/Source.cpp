#include <iostream>

using namespace std;

int main()
{
    int x, y;
    double r;
    cin >> x >> y;
    r = x;
    if (y > 0)
        for (int i = 0; i < y - 1; i++)
            r = r * x;
    if (y == 0)
        r = 1;
    else
        for (int i = 0; i < -y + 1; i++)
            r = r / x;
    cout << r;
    return 0;
}