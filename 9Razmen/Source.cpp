#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int dpMakeChange(int coinValueList[], int change, int minCoins[])
{
    for (int cents = 0; cents <= change; cents++)
    {
        int coinCount = cents;
        for (int j = 0; j < 5; j++)
        {
            if (coinValueList[j] <= cents)
            {
                
                int k = coinValueList[j];
                if (minCoins[cents - k] + 1 < coinCount)
                    coinCount = minCoins[cents - k] + 1;
            }
        }
        minCoins[cents] = coinCount;
    }
    return minCoins[change];
}
int main()
{
    setlocale(LC_ALL, "Russian");
    //20 - макс кол-во вариантов монет, можно повысить
    int N, A[5],mincoins[1000];
    A[0] = 1;
    A[1] = 2;
    A[2] = 5;
    A[3] = 7;
    A[4] = 10;
    for (int i = 0; i < 1000; i++)
        mincoins[i] = 0;

    cout << "Введите сумму" << endl;
    cin >> N;
    cout << dpMakeChange(A, N, mincoins) << " монеток придется достать";


    //cout << endl << schetchik << " монеток придется достать";
    return 0;
}